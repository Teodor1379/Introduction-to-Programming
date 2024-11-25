#include <stdio.h>

int main() {
    unsigned int    number      =   0;
    unsigned int    reversed    =   0;

    printf("Enter the number: ");

    scanf("%u", &number);

    while (number > 0) {
        unsigned int digit = number % 10;
        reversed = reversed * 10 + digit;
        number = number / 10;
    }

    printf("The reversed number is: %u\n", reversed);

    return 0;
}
