/*
    Purpose:    Show the use of the open(), read(), write() and close() system calls and the STDIN_FILENO.
    Example:    Reading without the use of scanf().
    Author:     Nick Sotiropoulos
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char buffer[1024];

    int bytes_read = read(STDIN_FILENO, buffer, 1024);
    if (bytes_read == -1)
    {
        perror("Error in read");
        exit(EXIT_FAILURE);
    }
    else 
        printf("\nI read \'%s\'\n", buffer);
    
    exit(EXIT_SUCCESS);
}