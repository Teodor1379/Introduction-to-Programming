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

    printf("Enter the number N: "); if (scanf("%u", &n) != 1)   { puts("Invalid Input!");   return 1;   }
    printf("Enter the number R: "); if (scanf("%u", &r) != 1)   { puts("Invalid Input!");   return 1;   }

    if (r >= 8 * sizeof(unsigned int)) {
        printf("Invalid value for R!\n");

        return 1;
    }


    printf("The old version of the number is: ");

    printNumberBinary(n);

    n = (n ^ (1 << r));

    printf("The new version of the number is: ");

    printNumberBinary(n);

    printf("The number itself is: %u\n", n);


    return 0;
}
