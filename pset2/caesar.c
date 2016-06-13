#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argv[1] == NULL) {
        printf("usage: ./caesar + shift\n");
        return 1;
    }
    string input = GetString();
    int shift = atoi(argv[1]);
    for (int i = 0; i < strlen(input); i++) {
            if (input[i] >= 'a' && input [i] <= 'z'){
                int result = input[i] - 'a';
                int new_result = (result + shift) % 26;
                printf("%c", new_result + 'a');
            }
            else if (input[i] >= 'A' && input[i] <= 'Z') {
                int result = input[i] - 'A';
                int new_result = (result + shift) % 26;
                printf("%c", new_result + 'A');
            }
            else {
                printf("%c", input[i]);
            }
        }
    printf("\n");
}