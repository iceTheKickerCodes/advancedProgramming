/*
    Purpose:    Show the use of the open(), read(), write() and close() system calls and the STDOUT_FILENO.
    Example:    Creating our own IO functions.
    Author:     Nick Sotiropoulos
*/


#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
#include <string.h>
#include <sys/stat.h>

void my_print(const char* buf);
void my_scan(void *buf);

int main(void)
{
    char buffer[1024];
    my_print("Give me something: ");
    my_scan((void *) buffer);
    my_print("You gave ");
    my_print((void *) buffer);
    exit(EXIT_SUCCESS);
}

void my_print(const char* buf)
{
    write(STDOUT_FILENO, buf, strlen(buf));
}

void my_scan(void *buf)
{
    read(STDIN_FILENO, buf, sizeof(buf));
}