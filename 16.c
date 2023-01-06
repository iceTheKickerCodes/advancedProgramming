/*
    Purpose:    Show the use of the dup() and dup2() system calls.
    Example:    Writing to a file using two file descriptors.
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // used for dup, dup2
#include <fcntl.h> 
#include <string.h>
#include <sys/stat.h>

/*
    int dup(int oldfd)

    Functionality
        The dup() system call allocates a new file descriptor that refers to
        the same open file description as the descriptor oldfd.
        The new file descriptor number is guaranteed to be the lowest-numbered
        file descriptor that was unused in the calling process
    Return Value
        Success: The return value is the new file descriptor 
        Error: The return value is -1.
*/

/*
    int dup2(int oldfd, int newfd)
    
    Functionality
        The dup2() system call does the exact same thing as dup() with the difference
        that the new file descriptor number is the one specified in newfd.
    Return Value
        Success: The return value is the new file descriptor 
        Error: The return value is -1.
*/

int main(void)
{
    char buffer[1024] = "This is going to be written inside the file.";
    char buffer2[1024] = " And me too!!";
    int fd = open("./newdupfile.txt", O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);
    if (fd < 0)
    {
        perror("Error in open");
        exit(EXIT_FAILURE);
    }

    if (write(fd, buffer, strlen(buffer)) == -1)
    {
        perror("Error in write");
        exit(EXIT_FAILURE);
    }
    printf("fd %d: I wrote \'%s\' to the file\n", fd, buffer);
    
    int fd2 = dup(fd);
    if (fd2 == -1)
    {
        perror("Error in dup");
        exit(EXIT_FAILURE);
    }
    
    if (write(fd2, buffer2, strlen(buffer2)) == -1)
    {
        perror("Error in write");
        exit(EXIT_FAILURE);
    }
    printf("fd %d: I wrote \'%s\' to the file\n", fd2, buffer2);

    if (close(fd) == -1 || close(fd2) == -1)
    {
        perror("Error in close");
        exit(EXIT_FAILURE);
    }

    exit(EXIT_SUCCESS);
}