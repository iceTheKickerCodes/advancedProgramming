/*
    Purpose:    Show the use of the dup() and dup2() system calls for IO redirection.
    Example:    Making printf() write to a file instead for the terminal.
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/stat.h>

int main(void)
{
    int fd = open("./mynewoutput.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd == -1)
    {
        perror("Error in open");
        exit(EXIT_FAILURE);
    }

    int old_stdout_fd = dup(STDOUT_FILENO);
    if (old_stdout_fd == -1)
    {
        perror("Error in dup");
        exit(EXIT_FAILURE);
    }


    int fd2 = dup2(fd, STDOUT_FILENO);
    if (fd2 == -1)
    {
        perror("Error in dup2");
        exit(EXIT_FAILURE);
    }
    
    printf("Hola amigos!\n");
    printf("I am Nick.\n");

    fflush(stdout);
    if (close(fd) == -1 || close(fd2) == -1)
    {
        perror("Error in close");
        exit(EXIT_FAILURE);
    }

    // Make the screen as the Standard Output back
    if (dup2(old_stdout_fd, STDOUT_FILENO) == -1)
    {
        perror("Error in dup2");
        exit(EXIT_FAILURE);
    }

    if (close(old_stdout_fd) == -1)
    {
        perror("Error in close");
        exit(EXIT_FAILURE);
    }

    printf("My password is 1234\n");

    exit(EXIT_SUCCESS);
}