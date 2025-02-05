#include <math.h>

#include <stdio.h>



void clearStandardInput();



unsigned int readNumber();



unsigned int countDigits(unsigned int number);



unsigned int LuciferNumberHelper(unsigned int number, unsigned int index);



int isLuciferNumber(unsigned int number);



int main() {
    unsigned int number =   readNumber();


    printf("Is the number Lucifer's: %s\n", isLuciferNumber(number) ? "Yes" : "No");


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readNumber() {
    unsigned int numb   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the number: ");

        inputArgument = scanf("%u", &numb);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return numb;
}



unsigned int countDigits(unsigned int number) {
    if (number == 0) {
        return 0;
    }

    return 1 + countDigits(number / 10);
}



unsigned int LuciferNumberHelper(unsigned int number, unsigned int index) {
    if (index == 0) {
        return 0;
    }

    return (int)(pow(number % 10, index)) + LuciferNumberHelper(number / 10, index - 1);
}



int isLuciferNumber(unsigned int number) {
    return number == LuciferNumberHelper(number, countDigits(number));
}
