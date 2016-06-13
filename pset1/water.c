#include <stdio.h>
#include <cs50.h>

int i;

int main () {
    printf("How long is your shower time? (Minutes): ");
    int i = GetInt();
    printf("Equivalent number of bottle of water per shower is: %i.\n", i*12);
}