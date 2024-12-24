#include <stdio.h>



int main() {
    unsigned int n  =   0;
    
    printf("Enter the number N: ");

    if (scanf("%u", &n) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    unsigned int leastSignificantBit    = n                             & 1;
    unsigned int mostSignificantBit     = (n >> (sizeof(n) * 8 - 1))    & 1;

    printf("The least   significant bit of N is: %u\n", leastSignificantBit );
    printf("The most    significant bit of N is: %u\n", mostSignificantBit  );


    return 0;
}
