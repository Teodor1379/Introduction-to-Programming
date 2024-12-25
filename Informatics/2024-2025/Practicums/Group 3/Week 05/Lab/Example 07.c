#include <stdio.h>



int main() {
    unsigned int number = 0;

    printf("Enter the number: ");

    if (scanf("%u", &number) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    if (number % 2 == 0) {
        for (unsigned int i = 0; i <= number; i += 2) {
            printf("%d ", i);
        }

        putchar('\n');
    } else {
        for (unsigned int i = 1; i <= number; i += 2) {
            printf("%d ", i);
        }

        putchar('\n');
    }


    return 0;
}
