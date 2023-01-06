/*
    Purpose:    Create a new process
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <unistd.h>         // used for fork
#include <sys/types.h>

/*
    pid_t fork(void)
    
    Functionality
        Creates a new process by duplicating the calling process. The new process
        is referred to as the child process. The calling process is referred to as
        the parent process.

        The child process and the parent process run in separate memory spaces.
        At the time of fork() both memory spaces have the same content. Memory
        writes, file mappings and unmappings performed by one of the processes
        do not affect the other process.

    Return Value
        Success: 
            The PID of the child process is returned to the parent. 
            0 is returned to the child.
        Error: -1 
*/

int main(void)
{
    pid_t my_id, child;

    child = fork();
    my_id = getpid();
    printf("Hey! Just want to let you know that my_id is %d and child is %d\n", my_id, child);
    return 0;
}