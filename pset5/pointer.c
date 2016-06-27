// A program to test for pointer segmentation fault!

#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    int* x;
    int* y;

    x = malloc(sizeof(int));
    y = NULL;

    *x = 42;

    *y = 13;

    y = x;

    *y = 13;
    
    printf("%i", *x);
    printf("%i", *y);
}