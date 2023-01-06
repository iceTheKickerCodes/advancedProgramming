/*
    Purpose:    Show that the memory spaces of the two processes are different.
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>       // used for wait

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
        printf("CHILD: I am going to change a to 5 and the name to Nico\n");
        a = 5;
        name[3] = 'o';
        printf("CHILD: a=%d and name=%s\n", a, name);
        exit(EXIT_SUCCESS);
    }
    else 
    {
        // parent's code
        if (wait(NULL) == -1)
        {
            perror("Error in wait");
            exit(EXIT_FAILURE);
        }

        pid_t my_id = getpid();
        printf("PARENT: a=%d and name=%s\n", a, name);
        exit(EXIT_SUCCESS);
    }
}