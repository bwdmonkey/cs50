#include <stdio.h>
#include <cs50.h>
#include <math.h>

//prototype
int coin_calc();
int cent_calc();

int main () {
    float total = 0;
    int cent = 0, num_coin = 0;
    
    do {
        printf("What is the change that needs to be calculated? ");
        total = GetFloat();
        if (total == 0 || total <=0) {
            printf("The number should be greater than 0.\n");
        }
    } while (total <= 0);
   
    //Changing dollars to cents, and rounding off floats
    cent = (int)round(total*100);
   
    num_coin = coin_calc(25, cent);
    cent = cent_calc(25,cent);
    num_coin = coin_calc(10, cent);
    cent = cent_calc(10,cent);
    num_coin = coin_calc(5, cent);
    cent = cent_calc(5,cent);
    num_coin = (1, cent);
    
    printf("Total: %i\n", num_coin);
    
    return(0);
}
int coin_calc(int coin, int cent) {
    int num_coin = 0;
    do {
        num_coin = num_coin + (cent / coin);
    }
    while (num_coin < 0);
    return(0);
}

int cent_calc(int coin, int cent) {
    do {
        cent = cent % coin;
    }
    while (cent < 0);
    return(0);
}