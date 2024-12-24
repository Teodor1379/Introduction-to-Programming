#include <stdio.h>



int main() {
    char c  =   '\0';

    printf("Enter the character: ");
    
    if (scanf("%c", &c) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    if (c >= 'A' && c <= 'Z') {
        puts("Uppercase Letter");
    } else if (c >= 'a' && c <= 'z') {
        puts("Lowercase Letter");
    } else if (c >= '0' && c <= '9') {
        puts("Number");
    } else {
        puts("Other");
    }


    return 0;
}
