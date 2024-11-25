#include <stdio.h>

int main() {
    unsigned int number = 0;

    printf("Enter the number: ");

    scanf("%u", &number);

    unsigned int reversed   =   0       ;
    unsigned int temporary  =   number  ;

    while (temporary > 0) {
        unsigned int digit = (temporary % 10);
        reversed    = reversed * 10 + digit;
        temporary   = temporary / 10;
    }

    if (number == reversed) {
        puts("Valid");
    } else {
        puts("Invalid");
    }

    return 0;
}
