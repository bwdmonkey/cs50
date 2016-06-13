#include <stdio.h>
#include <cs50.h>
#include <math.h>

#define QUARTER 25

//prototype
void coin_calc();

int main () {
    float total = 0;
    int cent = 0, quarter_count = 0, dime_count = 0, nickel_count = 0, penny_count = 0, leftover = 0, num_coin = 0;
    
    do {
        printf("What is the change that needs to be calculated? ");
        total = GetFloat();
        if (total == 0 || total <=0) {
            printf("The number should be greater than 0.\n");
        }
    } while (total <= 0);
   
    //Changing dollars to cents, and rounding off floats
    cent = (int)round(total*100);
   
    //quarter
    quarter_count = cent / 25;
    leftover = cent % 25;
    
    //dime
    dime_count = leftover / 10;
    leftover = leftover % 10;
   
    //nickel
    nickel_count = leftover / 5;
    leftover = leftover % 5;
    
    //penny
    penny_count = leftover;
    
    printf("The number of quarter(s) given: %i\n", quarter_count);
    printf("The number of dime(s) given: %i\n", dime_count);
    printf("The number of nickel(s) given: %i\n", nickel_count);
    printf("The number of penny(s) given: %i\n", penny_count);
    
    num_coin = quarter_count + dime_count + nickel_count + penny_count;
    printf("Total: %i\n", num_coin);
}
