#include <stdio.h>



int main() {
    unsigned int x  =   0;
    unsigned int y  =   0;

    printf("Enter the number X: "); if (scanf("%u", &x) != 1)   { puts("Input Error!"); return 1;   }
    printf("Enter the number Y: "); if (scanf("%u", &y) != 1)   { puts("Input Error!"); return 1;   }


    printf("The bitwise NOT of X is: %u\n", ~x);
    printf("The bitwise NOT of Y is: %u\n", ~y);

    printf("The bitwise AND of X and Y is: %u\n",   x & y);
    printf("The bitwise OR  of X and Y is: %u\n",   x | y);
    printf("The bitwise XOR of X and Y is: %u\n",   x ^ y);


    return 0;
}
