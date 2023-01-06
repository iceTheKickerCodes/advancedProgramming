/*
    Purpose:    Create a program that prints the PID of the process that runs it
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>          // used for printf
#include <unistd.h>         // used for getpid
#include <sys/types.h>      // used for pid_t type

/* 
    pid_t getpid(void);
    
    Functionality
        Returns the process ID of the process that called it
*/

int main(void)
{
    pid_t my_id;
    my_id = getpid();
    printf("My id is %d\n", my_id);
    return 0;
}