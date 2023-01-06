/*
    Purpose:    Show that the memory spaces of the two processes are different.
    Example:    Filling an array from the parent when child already exists.
    Author:     Nick Sotiropoulos
*/

#include <stdio.h>
#include <stdlib.h>     // used for srand and rand
#include <time.h>       // used for time
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


void fill_array(int A[], int N);
void print_array(int A[], int N);

int main(void)
{
    int A[10];
    srand(time(0));

    pid_t child = fork();
    if (child < 0)
    {
        perror("Error in fork");
        exit(EXIT_FAILURE);
    }
    else if (child == 0)
    {
        // child's code
        printf("CHILD: My array is ");
        print_array(A, 10);
        exit(EXIT_SUCCESS);
    }
    else 
    {
        // parent's code
        fill_array(A, 10);
        printf("PARENT: My array is ");
        print_array(A, 10);
        if (wait(NULL) == -1)
        {
            perror("Error in wait");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);
    }
}

void fill_array(int A[], int N)
{
    int i;
    for (i=0; i<N; i++)
        A[i] = rand()%20;
}

void print_array(int A[], int N)
{
    int i;
    printf("{");
    for (i=0; i<N-1; i++)
        printf("%d, ", A[i]);
    printf("%d}\n", A[i]);
}