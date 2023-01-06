/*
    Purpose:    Show the use of the execvp() system call.
    Example:    Executing the "ls -l" command using C.
    Author:     Nick Sotiropoulos
*/

#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    char command[] = "ls";
    char *command_list[] = {"ls", "-l", NULL};
    execvp(command, command_list);
    exit(EXIT_FAILURE);
}