/*
    Purpose:    Show the use of the pipe() system call.
    Example:    Sending a message from the child to the parent.
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>         // used for pipe
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/*
    int pipe(int pipefd[2])
    
    Functionality:
        It creates a pipe, a unidirectional data channel that can be used for 
        interprocess communication. The array pipefd is used to return two
        file descriptors referring to the ends of the pipe.
            pipefd[0] refers to the read end of the pipe
            pipefd[1] refers to the write end of the pipe
        Data written to the write end of the pipe is buffered by the kernel until 
        it is read from the read end of the pipe.
    Return Value
        Success: 0
        Error: -1
*/

int main(void)
{
    int pipefd[2];

    if (pipe(pipefd) == -1)
    {
        perror("Error in pipe");
        exit(EXIT_FAILURE);
    }

    pid_t child = fork();
    if (child == -1)
    {
        perror("Error in fork");
        exit(EXIT_FAILURE);
    }
    else if (child == 0)
    {
        // child's code
        if (close(pipefd[0]) == -1)
        {
            perror("Error in close");
            exit(EXIT_FAILURE);
        }

        char send[] = "Hello parent. If you read this, I am probably dead.";
        printf("CHILD: I sent \'%s\', rofl\n", send);
        if (write(pipefd[1], send, strlen(send)) == -1)
        {
            perror("Error in write");
            exit(EXIT_FAILURE);
        }

        if (close(pipefd[1]) == -1)
        {
            perror("Error in close");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }
    else
    {
        // father's code
        if (wait(NULL) == -1)
        {
            perror("Error in wait");
            exit(EXIT_FAILURE);
        }

        if (close(pipefd[1]) == -1)
        {
            perror("Error in close");
            exit(EXIT_FAILURE);
        }

        char receive[1024];
        if (read(pipefd[0], receive, 1024) == -1)
        {
            perror("Error in read");
            exit(EXIT_FAILURE);
        }
        printf("FATHER: I received \'%s\'. R.I.P.\n", receive);

        if (close(pipefd[0]) == -1)
        {
            perror("Error in close");
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    }
}