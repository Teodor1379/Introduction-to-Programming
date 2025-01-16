#include <stdio.h>



void clearStandardInput();



unsigned int readNumber();



unsigned int sumNumbers     (unsigned int number1, unsigned int number2);
unsigned int productNumbers (unsigned int number1, unsigned int number2);
unsigned int powerNumbers   (unsigned int number1, unsigned int number2);



int main() {
    unsigned int number1 = readNumber();
    unsigned int number2 = readNumber();

    unsigned int result1 = sumNumbers       (number1, number2);
    unsigned int result2 = productNumbers   (number1, number2);
    unsigned int result3 = powerNumbers     (number1, number2);

    printf("The Result 1 is: %u\n", result1);
    printf("The Result 2 is: %u\n", result2);
    printf("The Result 3 is: %u\n", result3);


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readNumber() {
    unsigned int number = 0;
    int inputArgument   = 0;

    do {
        printf("Enter the number: ");

        inputArgument = scanf("%u", &number);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return number;
}



unsigned int sumNumbers(unsigned int number1, unsigned int number2) {
    /*  The Recursive Definition is:

        a + b = a                   , b = 0
        a + b = (a + 1) + (b - 1)   , b > 0
    */

    if (number2 == 0) {
        return number1;
    }

    return sumNumbers(number1 + 1, number2 - 1);
}

unsigned int productNumbers(unsigned int number1, unsigned int number2) {
    /*  The Recursive Definition is:

        a * b = 0                   , b = 0
        a * b = 1                   , b = 1
        a * b = a + a * (b - 1)     , b > 1
    */

    if (number2 == 0) {
        return 0;
    }

    if (number1 == 1) {
        return number1;
    }

    return number1 + productNumbers(number1, number2 - 1);
}

unsigned int powerNumbers(unsigned int number1, unsigned int number2) {
    /*  The Recursive Definition is:

        a ^ b = 1                   , b = 0
        a ^ b = a * (a ^ (b - 1))   , b > 0
    */

    if (number2 == 0) {
        return 1;
    }

    return number1 * powerNumbers(number1, number2 - 1);
}
