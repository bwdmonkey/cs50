#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

#PROTYPE
int values[];
const int MAX = 65536;

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: ./find needle\n");
        return -1;
    }

    // remember needle
    int needle = atoi(argv[1]);

    // fill haystack
    int size;
    int haystack[MAX];
    for (size = 0; size < MAX; size++)
    {
        // wait for hay until EOF
        printf("\nhaystack[%i] = ", size);
        int straw = GetInt();
        if (straw == INT_MAX)
        {
            break;
        }
     
        // add hay to stack
        haystack[size] = straw;
    }
    printf("\n");

    // sort the haystack
    sort(haystack, size);
    
    printf("%i", values[0]);
}

void sort(int values[], int n)
{
    int smallest = 0;
    
    for (int j = 0; j < n-1; j++) {
        if (values[j] < smallest) {
            smallest = values[j];
        }
    }
    
    return;
}