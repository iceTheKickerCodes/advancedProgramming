/*
    Purpose:    Show the wait() system call
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>       // used for wait

/*
    pid_t wait(int *wstatus);

    Functionality
        The wait() system call suspends execution of the calling thread until one of it's
        children terminates. 
    Return Value
        Success: The PID of the terminated child.
        Error: -1
*/

int main(void)
{
    int a = 30;
    char name[] = "Nick";

    pid_t child = fork();

    if (child < 0)
    {
        perror("Error in fork");
        exit(EXIT_FAILURE);
    }
    else if (child == 0)
    {
        // child's code
        pid_t my_id = getpid();
        pid_t parent_id = getppid();
        printf("CHILD: Hey! Just want to let you know that I am the child. I can prove it, because my_id is %d and parent_id is %d\n", my_id, parent_id);
        printf("CHILD: Also, a=%d and name=%s\n", a, name);
        printf("CHILD: Now I am exiting with status %d\n", EXIT_SUCCESS);
        exit(EXIT_SUCCESS);
    }
    else 
    {
        // parent's code
        printf("PARENT: I am going to wait for my child to exit first\n");
        
        int exit_status_of_child;
        if(wait(&exit_status_of_child) == -1)
        {
            perror("Error in wait");
            exit(EXIT_FAILURE);
        }
        printf("PARENT: My child exited with status %d\n", exit_status_of_child);
        printf("PARENT: Now I can run the rest of my code\n");
        
        pid_t my_id = getpid();
        printf("PARENT: Hey! Just want to let you know that I was :( the parent. I can prove it because my_id is %d and child was %d\n", my_id, child);
        printf("PARENT: Also, a=%d and name=%s\n", a, name);
        exit(EXIT_SUCCESS);
    }

    // Whatever is written here won't ever be executed because both parent and child processes have already exited
    printf("rofl\n");
}