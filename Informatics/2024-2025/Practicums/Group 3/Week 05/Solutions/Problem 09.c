#include <stdio.h>



int main() {
    unsigned int n = 0;

    do {
        printf("Enter the number N: ");

        if (scanf("%u", &n) != 1) {
            puts("Invalid Input!");

            return 1;
        }
    } while (n == 0);


    for (unsigned int i = 1; i <= n; ++i) {
        for (unsigned int j = 1; j <= n; ++j) {
            if (i < j) {
                putchar('+');
            } else if (i > j) {
                putchar('-');
            } else {
                putchar('0');
            }
        }

        putchar('\n');
    }


    return 0;
}
