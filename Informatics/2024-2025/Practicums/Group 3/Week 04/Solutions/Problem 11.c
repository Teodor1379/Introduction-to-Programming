#include <stdio.h>



#define SIZE 32



void printNumberBinary(char number) {
    unsigned int array[SIZE] = { 0 };

    unsigned int counter = SIZE - 1;

    while (number > 0) {
        array[counter] = number % 2;

        number  =   number      / 2;
        counter =   counter     - 1;
    }

    for (unsigned int i = 0; i < SIZE; ++i) {
        printf("%u", array[i]);
    }

    putchar('\n');
}



int main() {
    unsigned int number = 0;

    printf("Enter the number: ");

    if (scanf("%u", &number) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    printNumberBinary(number);


    unsigned int bit1 = (number >> 0) & 1;
    unsigned int bit2 = (number >> 1) & 1;
    unsigned int bit3 = (number >> 2) & 1;
    unsigned int bit4 = (number >> 3) & 1;
    unsigned int bit5 = (number >> 4) & 1;
    unsigned int bit6 = (number >> 5) & 1;
    unsigned int bit7 = (number >> 6) & 1;
    unsigned int bit8 = (number >> 7) & 1;

    unsigned int sum1 = bit1 + bit2 + bit3 + bit4;
    unsigned int sum2 = bit5 + bit6 + bit7 + bit8;

    unsigned int ones = sum1 + sum2;

    printf("The number of bits with value 1 is: %u\n", ones);


    return 0;
}
