#include <stdio.h>



int main() {
    int n = 0;

    do {
        printf("Enter the number N: ");

        if (scanf("%d", &n) != 1) {
            puts("Invalid Input!");

            return 1;
        }
    } while (n <= 0);


    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n - i; ++j) {
            putchar(' ');
            putchar(' ');
        }

        for (int j = 1; j <= i; ++j) {
            printf("%d ", j);
        }

        for (int j = i - 1; j >= 1; --j) {
            printf("%d ", j);
        }

        putchar('\n');
    }

    for (int i = n - 1; i >= 1; --i) {
        for (int j = 1; j <= n - i; ++j) {
            putchar(' ');
            putchar(' ');
        }

        for (int j = 1; j <= i; ++j) {
            printf("%d ", j);
        }

        for (int j = i - 1; j >= 1; --j) {
            printf("%d ", j);
        }

        putchar('\n');
    }


    return 0;
}
