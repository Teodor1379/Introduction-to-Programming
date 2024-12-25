#include <stdio.h>



int main() {
    unsigned int current = 1;

    printf("Enter the numbers: ");


    unsigned int sum = 0;

    while (current != 0) {
        if (scanf("%u", &current) != 1) {
            puts("Invalid Input!");

            return 1;
        }

        if (current == 0) {
            break;
        }

        sum = sum + current;
    }

    printf("The sum of the numbers is: %u\n", sum);


    return 0;
}
