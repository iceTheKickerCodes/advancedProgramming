/*
    Purpose:    Show the use of the open(), read(), write() and close() system calls.
    Example:    Writing to a file.
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include <string.h>     // used for strlen
#include <sys/stat.h>   // used for S_IRWXU

int main(void)
{
    char buffer[1024] = "This is going to be written inside the file.";
    int fd = open("./newfile.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    if (fd < 0)
    {
        perror("Error in open");
        exit(EXIT_FAILURE);
    }

    int bytes_written = write(fd, buffer, strlen(buffer));
    if (bytes_written == -1)
    {
        perror("Error in write");
        exit(EXIT_FAILURE);
    }
    else 
        printf("I wrote \'%s\' to the file\n", buffer);
    
    int close_rv = close(fd);
    if (close_rv == -1)
    {
        perror("Error in close");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}