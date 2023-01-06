/*
    Purpose:    Show the exit() system call in contrast to return
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <stdlib.h>         // used for EXIT_SUCCESS and EXIT_FAILURE
#include <unistd.h>
#include <sys/types.h>

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
        exit(EXIT_SUCCESS);
    }
    else 
    {
        // parent's code
        pid_t my_id = getpid();
        printf("PARENT: Hey! Just want to let you know that I am the parent. I can prove it because my_id is %d and child is %d\n", my_id, child);
        printf("PARENT: Also, a=%d and name=%s\n", a, name);
        exit(EXIT_SUCCESS);
    }

    // Whatever is written here won't ever be executed because both parent and child processes have already exited
    printf("rofl\n");
}