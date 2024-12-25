#include <stdio.h>



int main() {
    unsigned int number = 0;


    printf("Enter the number: ");

    if (scanf("%u", &number) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    for (unsigned int i = 1; i <= number; ++i) {
        printf("%d ", i);
    }

    putchar('\n');


    return 0;
}