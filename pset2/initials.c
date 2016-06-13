#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main() {
    string name = GetString();
    printf("%c", toupper(name[0]));
    for (int i = 0; i <= strlen(name); i++) {
        if (name[i] == ' ' && name[i+1] != '\0') {
            printf("%c", toupper(name[i+1]));
            i++;
        }
    }
    printf("\n");
}