#include <stdio.h>



int main() {
    unsigned int    n   =   0;
    unsigned int    d   =   0;
    unsigned int    t   =   0;

    printf("Enter the number N: "); if (scanf("%u", &n) != 1)   { puts("Invalid Input!");   return 1;   }
    printf("Enter the number D: "); if (scanf("%u", &d) != 1)   { puts("Invalid Input!");   return 1;   }


    while (n > 0) {
        unsigned int digit = n % 10;
        t = t + (digit == d ? 1 : 0);
        n = n / 10;
    }

    printf("The result is: %u\n", t);


    return 0;
}
