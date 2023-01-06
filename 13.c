/*
    Purpose:    Show the use of the open(), read(), write() and close() system calls and the STDOUT_FILENO.
    Example:    Printing without the use of printf().
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char buffer[1024] = "This is going to be written on the screen.";

    int bytes_written = write(STDOUT_FILENO, buffer, strlen(buffer));
    if (bytes_written == -1)
    {
        perror("Error in write");
        exit(EXIT_FAILURE);
    }
    else 
        printf("\nI wrote \'%s\' on the screen\n", buffer);
    
    exit(EXIT_SUCCESS);
}