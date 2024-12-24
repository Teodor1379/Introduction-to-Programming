#include <stdio.h>



int main() {
    // Bit Set


    unsigned int number     =   0;
    unsigned int position   =   0;


    printf("Enter the number: ");

    if (scanf("%u", &number) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    printf("Enter the position: ");

    if (scanf("%u", &position) != 1) {
        puts("Invalid Input!");

        return 1;
    }

    if (position >= 8 * sizeof(unsigned int)) {
        puts("Invalid bit position!");

        return 1;
    }


    printf("Bit Set: %u\n", number | (1 << position));


    return 0;
}