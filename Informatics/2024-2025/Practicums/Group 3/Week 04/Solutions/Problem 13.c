#include <stdint.h>

#include <stdio.h>



#define SIZE 32



void printNumberBinary(char number) {
    unsigned int array[SIZE] = { 0 };

    unsigned int counter = SIZE - 1;

    while (number > 0) {
        array[counter] = number % 2;

        number  = number    / 2;
        counter = counter   - 1;
    }

    for (unsigned int i = 0; i < SIZE; ++i) {
        printf("%u", array[i]);
    }

    putchar('\n');
}



int main() {
    uint8_t number1 = '\0';
    uint8_t number2 = '\0';

    printf("Enter the numbers: ");

    if (scanf("%hhu %hhu", &number1, &number2) != 2) {
        puts("Invalid Input!");

        return 1;
    }


    printNumberBinary(number1);
    printNumberBinary(number2);


    unsigned int difference1 = (((number1 >> 0) & 1) != ((number2 >> 0) & 1));
    unsigned int difference2 = (((number1 >> 1) & 1) != ((number2 >> 1) & 1));
    unsigned int difference3 = (((number1 >> 2) & 1) != ((number2 >> 2) & 1));
    unsigned int difference4 = (((number1 >> 3) & 1) != ((number2 >> 3) & 1));
    unsigned int difference5 = (((number1 >> 4) & 1) != ((number2 >> 4) & 1));
    unsigned int difference6 = (((number1 >> 5) & 1) != ((number2 >> 5) & 1));
    unsigned int difference7 = (((number1 >> 6) & 1) != ((number2 >> 6) & 1));
    unsigned int difference8 = (((number1 >> 7) & 1) != ((number2 >> 7) & 1));

    unsigned int sum1 = difference1 + difference2 + difference3 + difference4;
    unsigned int sum2 = difference5 + difference6 + difference7 + difference8;

    unsigned int result = sum1 + sum2;


    printf("The Hamming distance is: %u\n", result);

    return 0;
}
