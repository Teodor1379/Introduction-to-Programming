#include <assert.h>

#include <stdio.h>



void clearStandardInput();



int readNumber();



int readNumberInterval(int min, int max);



int main() {
    printf("Enter the interval: ");

    int minNumber = readNumber();
    int maxNumber = readNumber();

    printf("The MIN number is: %d\n",   minNumber);
    printf("The MAX number is: %d\n",   maxNumber);


    int number = readNumberInterval(minNumber, maxNumber);

    printf("The number in the interval is: %d\n", number);

    
    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



int readNumber() {
    int number          =   0;
    int inputArguments  =   0;

    do {
        inputArguments = scanf("%d", &number);

        if (inputArguments != 1) {
            clearStandardInput();
        }
    } while (inputArguments != 1);

    return number;
}



int readNumberInterval(int min, int max) {
    assert(min <= max);

    int number = 0;

    do {
        printf("Enter the number: ");

        number = readNumber();
    } while (number < min || number > max);

    return number;
}
