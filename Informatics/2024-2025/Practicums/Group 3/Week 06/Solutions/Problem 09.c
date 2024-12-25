#include <stdio.h>



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



int conditionSumDigits(unsigned int number) {
    if (number < 100) {
        return 0;
    }

    unsigned int previous1 = number % 10;   number = number / 10;
    unsigned int previous2 = number % 10;   number = number / 10;

    while (number > 0) {
        unsigned int digit = number % 10;

        if (digit != previous1 + previous2) {
            return 0;
        }

        previous1 = previous2;
        previous2 = digit;

        number = number / 10;
    }

    return 1;
}



int main() {
    unsigned int number = 0;

    do {
        printf("Enter number: ");

        if (scanf("%u", &number) != 1) {
            puts("Invalid Input!");

            clearStandardInput();
        }
    } while (number == 0);


    printf("%s\n", conditionSumDigits(number) ? "Yes" : "No");


    return 0;
}
