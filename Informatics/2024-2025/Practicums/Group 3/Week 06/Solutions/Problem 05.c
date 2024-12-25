#include <stdio.h>



int sameDigits(long long number) {
    if (number < 10) {
        return 0;
    }

    if (number >= 10 && number < 100) {
        return (number % 10) == ((number / 10) % 10);
    }

    int digit = number % 10;

    number = number / 10;

    while (number > 0) {
        int current = number % 10;

        if (digit == current) {
            return 1;
        }

        digit = current;
        number = number / 10;
    }

    return 0;
}

void findNumbersSameDigits(long long a, long long b) {
    printf("The numbers are: ");

    for (long long i = a; i <= b; ++i) {
        if (sameDigits(i)) {
            printf("%lld ", i);
        }
    }

    putchar('\n');
}



int main() {
    long long   a   =   0;
    long long   b   =   0;

    do {
        printf("Enter the number A: "); if (scanf("%lld", &a) != 1) { puts("Invalud Input!");   return 1;   }
        printf("Enter the number B: "); if (scanf("%lld", &b) != 1) { puts("Invalid Input!");   return 1;   }
    } while (a > b);

    findNumbersSameDigits(a, b);

    return 0;
}
