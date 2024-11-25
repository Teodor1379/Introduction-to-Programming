#include <stdio.h>

int main() {
    unsigned int number = 0;

    printf("Enter the number: ");

    scanf("%u", &number);

    if (number <= 1) {
        printf("The number is not prime!\n");
    } else {
        int isPrime = 1;

        for (unsigned int i = 2; i < number; ++i) {
            if (number % i == 0) {
                isPrime = 0;
                break;
            }
        }

        if (isPrime) {
            printf("The number is prime!\n");
        } else {
            printf("The number is not prime!\n");
        }
    }

    return 0;
}
