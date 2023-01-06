/*
    Purpose:    Show the use of the execvp() system call.
    Example:    Executing the "ls" command using C.
    Author:     Nick Sotiropoulos
*/

#include <unistd.h>     // used for execvp
#include <stdlib.h>

int main(void)
{
    char command[] = "ls";
    char *command_list[] = {"ls", NULL};
    execvp(command, command_list);
    exit(EXIT_FAILURE);
}