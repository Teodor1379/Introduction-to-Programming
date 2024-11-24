#include <stdio.h>

unsigned int fibonacci(unsigned int n) {
    if (n < 2) {
        return n;
    }

    unsigned int number1    =   0;
    unsigned int number2    =   1;
    unsigned int number3    =   0;
    unsigned int counter    =   2;

    while (counter <= n) {
        number3 = number2;
        number2 = number1 + number2;
        number1 = number3;

        counter = counter + 1;
    }

    return number2;
}

int main() {
    unsigned int n = 0;

    do {
        printf("Enter the number: ");
        scanf("%u", &n);
    } while (n == 0);

    printf("The number of Fibonacci is: %u\n", fibonacci(n));

    return 0;
}
