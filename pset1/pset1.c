#include <stdio.h>
#include <cs50.h>

int i;

int main () {
    printf("Give me a number: ");
    int i = GetInt();
    printf("You gave a number of %i.\n", i);
    printf("Multiplying your number by 2: %i.\n", i*2);
}