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
    unsigned int n = 0;

    printf("Enter the power N: ");

    if (scanf("%u", &n) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    printNumberBinary(n);


    printf("2 to the power of N is: %u\n",  1 << (n - 0));
    printf("2 to the power of N is: %u\n",  2 << (n - 1));


    return 0;
}
