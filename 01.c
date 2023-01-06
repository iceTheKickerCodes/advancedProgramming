/*
    Purpose:    Create a program that prints the PID of the process that runs it and also it's parent PID
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <unistd.h>         // used for getppid
#include <sys/types.h>

/* 
    Get Parent Process ID
    pid_t getppid(void);
    
    Functionality
        Returns the process ID of the parent of the process that called it
*/

int main(void)
{
    pid_t my_id, parent_id;

    

    my_id = getpid();
    parent_id = getppid();
    printf("My id is %d and my parent\'s id is %d\n", my_id, parent_id);
    return 0;
}