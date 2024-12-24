#include <stdio.h>



int main() {
    unsigned int    x   =   0;
    unsigned int    y   =   0;

    printf("Enter the number X: "); if (scanf("%u", &x) != 1)   { puts("Invalid Input!");   return 1;   }
    printf("Enter the number Y: "); if (scanf("%u", &y) != 1)   { puts("Invalid Input!");   return 1;   }


    x = x ^ y;
    y = x ^ y;
    x = x ^ y;

    printf("The result number X is: %u\n", x);
    printf("The result number Y is: %u\n", y);


    return 0;
}
