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
    unsigned int n  =   0;
    unsigned int s  =   0;

    printf("Enter the number N: "); if (scanf("%u", &n) != 1)   { puts("Invalid Input!");   return 1;   }
    printf("Enter the number S: "); if (scanf("%u", &s) != 1)   { puts("Invalid Input!");   return 1;   }

    if (s >= 8 * sizeof(unsigned int)) {
        printf("Invalid value for S!\n");

        return 1;
    }


    unsigned int bit = (n >> s) & 1;

    printNumberBinary(n);

    printf("The S-th bit of number N is: %u\n", bit);


    return 0;
}
