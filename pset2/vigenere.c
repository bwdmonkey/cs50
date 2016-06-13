#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char** argv) {
    if ( argc > 2 ){
    printf ("usage : ./vigenere + keyword \n");
    return 1;
    }
    else if ( argv[1] == NULL ){
    printf ("usage : ./vigenere + keyword \n");
    return 1;
    }
    char* keyword = argv[1];
        //printf("Ciphertext: ");
    string input = GetString();
    char output[strlen(input)];
        // printf("Keyword: ");
        // char* keyword = GetString();
    int shift = 0;
    int s = 0;
    for (int i = 0; i < strlen(input);i++, s++) {
        if ('A' <=keyword[s % strlen(keyword)] && keyword[s % strlen(keyword)] <= 'Z') {
            shift = keyword[s % strlen(keyword)] - 'A';
           }
        else if ('a' <=keyword[s % strlen(keyword)] && keyword[s % strlen(keyword)] <= 'z') {
            shift = keyword[s % strlen(keyword)] - 'a';
           }
        else {
            shift = keyword[s % strlen(keyword)];
           }
        // printf("%i\n", shift);
        if ('A' <= input[i] && input[i] <= 'Z') {
            output[i] = (((input[i]-'A') + shift) % 26) + 'A';
        }
        else if ('a' <= input[i] && input[i] <= 'z') {
            output[i] = (((input[i]-'a') + shift) % 26) + 'a';
        }
        else {
            output[i] = input[i];
            s--;
        }
    }
    printf("%s\n", output);
    return 0;
}

