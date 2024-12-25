#include <stdio.h>



int main() {
    unsigned int current = 0;

    printf("Enter the numbers: ");

    if (scanf("%u", &current) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    unsigned int min = current;
    unsigned int max = current;

    while (1) {
        if (scanf("%u", &current) != 1) {
            puts("Invalid Input!");

            return 1;
        }

        if (current == 0) {
            break;
        }

        if (min < current) {
            min = current;
        }

        if (max > current) {
            max = current;
        }
    }

    printf("The min number is: %u\n", min);
    printf("The max number is: %u\n", max);


    return 0;
}
