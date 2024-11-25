#include <stdio.h>

int main() {
    long long   n   =   0;
    long long   m   =   0;

    do {
        printf("Enter the number N: ");

        scanf("%lld", &n);
    } while (n <= 0);

    do {
        printf("Enter the number M: ");

        scanf("%lld", &m);
    } while (m <= 0);

    for (long long i = 1; i <= m; ++i) {
        for (long long j = 1; j <= n * (m - 1) + 1; ++j) {
            if (i == 1 || i == m) {
                putchar('*');
                putchar(' ');
            } else {
                if (j % (m - 1) == 1) {
                    putchar('*');
                    putchar(' ');
                } else {
                    putchar(' ');
                    putchar(' ');
                }
            }
        }

        putchar('\n');
    }

    return 0;
}
