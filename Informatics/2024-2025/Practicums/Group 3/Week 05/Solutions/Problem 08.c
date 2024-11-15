#include <stdio.h>

int main() {
    unsigned int    n   =   0;
    unsigned int    d   =   0;
    unsigned int    t   =   0;

    printf("Enter the number N: "); scanf("%u", &n);
    printf("Enter the number D: "); scanf("%u", &d);

    while (n > 0) {
        unsigned int digit = n % 10;
        t = t + (digit == d ? 1 : 0);
        n = n / 10;
    }

    printf("The result is: %u\n", t);

    return 0;
}
