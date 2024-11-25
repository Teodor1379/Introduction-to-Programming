#include <stdio.h>

int main() {
    unsigned int    n   =   0;

    printf("Enter the number N: ");

    scanf("%u", &n);

    unsigned int    sum     =   0;
    unsigned int    product =   1;

    for (unsigned int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            sum     =   sum     + i;
            product =   product * i;
        }
    }

    printf("The sum     of the divisors of N is: %u\n", sum     );
    printf("The product of the divisors of N is: %u\n", product );

    return 0;
}
