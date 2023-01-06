/*
    Purpose:    Show the connection between the child and parent process using their PIDs
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
    pid_t my_id, child;

    child = fork();
    if (child < 0)
    {
        perror("Error in fork");
        return 1;
    }
    else if (child == 0)
    {
        // child's code
        my_id = getpid();
        pid_t parent_id = getppid();
        printf("Hey! Just want to let you know that I am the child. I can prove it, because my_id is %d and parent_id is %d\n", my_id, parent_id);
    }
    else 
    {
        // parent's code
        my_id = getpid();
        printf("Hey! Just want to let you know that I am the parent. I can prove it because my_id is %d and child is %d\n", my_id, child);
    }

    return 0;
}