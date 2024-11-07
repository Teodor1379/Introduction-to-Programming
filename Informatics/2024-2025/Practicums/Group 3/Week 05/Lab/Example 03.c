#include <stdio.h>

int main() {
    unsigned int number = 0;

    printf("Enter a number: ");
    scanf("%u", &number);

    for (unsigned int i = 1; i <= number; ++i) {
        if (i % 2 == 1) {
            for (unsigned int j = 1; j <= i; j += 2) {
                printf("%u ", j);
            }

            putchar('\n');
        }
    }

    return 0;
}
