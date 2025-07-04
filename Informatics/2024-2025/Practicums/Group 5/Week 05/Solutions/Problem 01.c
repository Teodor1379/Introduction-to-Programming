#include <stdio.h>



int main() {
    unsigned int N = 0;

    do {
        printf("Enter the number N: ");

        if (scanf("%u", &N) != 1) {
            puts("Invalid Input!");

            return 1;
        }
    } while (N == 0);


    unsigned int factorial = 1;

    for (unsigned int i = 1; i <= N; ++i) {
        factorial = factorial * i;
    }

    printf("Factorial of %u is: %u.\n", N, factorial);


    return 0;
}
