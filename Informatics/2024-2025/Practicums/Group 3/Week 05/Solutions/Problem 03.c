#include <stdio.h>



int main() {
    unsigned int n = 0;

    printf("Enter the number N: ");

    if (scanf("%u", &n) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    unsigned int sumOdds    =   0;
    unsigned int sumEvens   =   0;

    for (unsigned int i = 1; i <= n; ++i) {
        sumOdds  = sumOdds  + (i % 2 == 0 ? 0 : i);
        sumEvens = sumEvens + (i % 2 == 0 ? i : 0); 
    }

    printf("The sum of the even numbers is: %u\n", sumOdds );
    printf("The sum of the odd  numbers is: %u\n", sumEvens);


    return 0;
}
