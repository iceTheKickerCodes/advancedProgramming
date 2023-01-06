/*
    Purpose:    Show the use of the open(), read(), write() and close() system calls.
    Example:    Try to read from a file that does not exist.
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 

int main(void)
{
    char buffer[1024];
    int fd = open("./nonexistent.txt", O_RDONLY);
    if (fd < 0)
    {
        perror("Error in open");
        exit(EXIT_FAILURE);
    }

    int bytes_read = read(fd, buffer, 1024);
    if (bytes_read == -1)
    {
        perror("Error in read");
        exit(EXIT_FAILURE);
    }
    else 
        printf("I read \'%s\' from the file\n", buffer);
    
    int close_rv = close(fd);
    if (close_rv == -1)
    {
        perror("Error in close");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}