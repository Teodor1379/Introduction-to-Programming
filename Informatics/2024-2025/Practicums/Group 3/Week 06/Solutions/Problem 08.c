#include <stdio.h>

void showCanonical(unsigned int number) {
    printf("The canonical of the number is: ");

    for (unsigned int i = 2; i <= number; ++i) {
        if (number % i == 0) {
            printf("%u ", i);
            number = number / i;
            i = i - 1;
        }
    }

    putchar('\n');
}

int main() {
    unsigned int n = 0;

    do {
        printf("Enter the number N: ");
        scanf("%u", &n);
    } while (n < 2);

    showCanonical(n);

    return 0;
}
