#include <stdio.h>



#define SIZE 32



void printNumberBinary(unsigned int number) {
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
    unsigned int number = 0;

    printf("Enter the number: ");

    scanf("%u", &number);

    printf("The binary form of the number is: ");

    printNumberBinary(number);

    printf("Is the number even? %s\n", (number & 1) ? "No" : "Yes");

    return 0;
}
