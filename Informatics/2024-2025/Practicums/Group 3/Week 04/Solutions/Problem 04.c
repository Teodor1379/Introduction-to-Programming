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
    unsigned int r = 0;

    printf("Enter the number N: "); scanf("%u", &n);
    printf("Enter the number R: "); scanf("%u", &r);

    printf("The old version of the number is: ");
    printNumberBinary(n);

    n = (n & ~(1 << r));

    printf("The new version of the number is: ");
    printNumberBinary(n);

    printf("The new number N is: %u\n", n);

    return 0;
}
