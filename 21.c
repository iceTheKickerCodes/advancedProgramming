/*
    Purpose:    Show the use of the execvp() system call.
    Example:    Creating a child to execute the "ls" command using C.
    Benefits:   The parent can continue doing other things.
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    printf("I am going to create a child which will execute the command ls.\n");
    pid_t child = fork();
    if (child == -1)
    {
        perror("Error in fork");
        exit(EXIT_FAILURE);
    }
    else if (child == 0)
    {
        char command[] = "ls";
        char *command_list[] = {"ls", NULL};
        execvp(command, command_list);
        exit(EXIT_FAILURE);
    }
    else 
    {
        int status;
        wait(&status);
        printf("My child terminated with status %d\n", status);
        printf("Goodbye!\n");
        exit(EXIT_SUCCESS);
    }
}