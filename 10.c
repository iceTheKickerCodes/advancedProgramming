/*
    Purpose:    Show the use of the open(), read(), write() and close() system calls.
    Example:    Reading from a file.
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>     // used for read, write and close
#include <fcntl.h>      // used for open

/*
    int open(const char *pathname, int flags);
    int open(const char *pathname, int flags, mode_t mode);

    Functionality
        Opens the file specified by pathname.
            If the file does not exist, it may optionally be created by open() if O_CREAT 
            is specified in flags.
    Return Value
        Success: The return value of open() is a file descriptor, a small nonnegative integer
            that is an index to an entry in the process's table of open file decriptors.
            The file descriptor is used in subsequent system calls (read(), write(), close()).
        Error: The return value is -1
    Flags 
        Necessary (at least one of them):
            O_RDONLY, O_WRONLY, O_RDWR
        Optional:
            O_APPEND: to write at the end of the file 
            O_TRUNC: to erase everything in the file and start writing it from scratch
    Mode:
        S_IRWXU: 00700  user has read, write, and execute permission
        S_IRUSR: 00400  user has read permission
        S_IRUSR: 00200  user has write permission
        S_IRUSR: 00100  user has execute permission
        etc..
*/

/*
    int close(int fd)

    Functionality
        Closes a file descriptor, so it no longer refers to any file and may be reused.
    Return Value
        Success: 0
        Error: -1
*/

/*
    ssize_t write(int fd, void* buf, size_t count)

    Functionality
        Attempts to read up to count bytes from the file refered to by the file descriptor fd 
        into the buffer starting at buf.
    
    Return Value
        Success: The number of numbers read is returned.
        Error: -1
*/


/*
    ssize_t write(int fd, const void* buf, size_t count)

    Functionality 
        Writes up to count bytes from the buffer starting at buf to the file refered to by 
        the file descriptor fd.
        The number of bytes written may be less than count.
    Return value
        Success: The number of bytes written is returned.
        Error: -1
*/

int main(void)
{
    char buffer[1024];
    int fd = open("./myfile.txt", O_RDONLY);
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