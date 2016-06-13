#include <stdio.h>
#include <cs50.h>
 
int height;
int line;
int space;
int hash; 
 
int main(void)
{
    // do while for no smaller than 0 and bigger than 23
    do
    {
        printf("Please choose a number upto 23: ");
        height = GetInt();
    }
    while ((height < 0) || (height > 23));
    // loop till the number of height
    for (line = 1; line <= height; line++) 
    {
        // looping the number of spaces (reducing)
        for (space = (height - line); space > 0; space--)
        {
            printf(" "); 
        }
        // looping the hashes (increasing)
        for (hash = 0; hash <= (line); hash++)
        {   
            printf("#"); 
        }
 
        printf("\n");
    }
    return 0;
}
