#include <stdio.h>



void clearStandardInput();



int readNumber();



int main() {
    printf("Enter the number: ");

    int number = readNumber();

    printf("The number is: %d\n", number);

    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



int readNumber() {
    int number          =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%d", &number);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return number;
}
