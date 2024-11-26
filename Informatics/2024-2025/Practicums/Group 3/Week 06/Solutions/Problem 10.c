#include <stdio.h>

int isEvenDigit (unsigned int number);
int isOddDigit  (unsigned int number);

int isDigitRed  (unsigned int number, int flag);
int isDigitBlack(unsigned int number, int flag);

unsigned int countDigits(unsigned int number);

unsigned int reversedNumber(unsigned int number);

unsigned int buildNumber(unsigned int number, char colour);

int isPalindrome(unsigned int number);

int calculateNumberRedDigits    (unsigned int number);
int calculateNumberBlackDigits  (unsigned int number);

void printInformationNumbers(unsigned int number);

int main() {
    unsigned int number = 0;

    do {
        printf("Eter the number: ");

        scanf("%u", &number);

        while (getchar() != '\n');
    } while (number == 0);

    printInformationNumbers(number);
    
    return 0;
}

int isEvenDigit(unsigned int number) {
    return  number < 10     &&
            number % 2 == 0;
}

int isOddDigit(unsigned int number) {
    return  number < 10     &&
            number % 2 == 1; 
}

int isDigitRed(unsigned int number, int flag) {
    return isOddDigit(number) && flag == 1;
}

int isDigitBlack(unsigned int number, int flag) {
    return isEvenDigit(number) && flag == 0;
}

unsigned int countDigits(unsigned int number) {
    unsigned int result = 0;

    while (number > 0) {
        result = result + 1;
        number = number / 10;
    }

    return result;
}

unsigned int reversedNumber(unsigned int number) {
    unsigned int reversed   =   0;

    while (number > 0) {
        unsigned int digit = number % 10;
        number = number / 10;
        reversed = reversed * 10 + digit;
    }

    return reversed;
}

unsigned int buildNumber(unsigned int number, char colour) {
    unsigned int result = 0;
    unsigned int digits = countDigits(number);

    unsigned int flag = digits % 2;

    while (number > 0) {
        unsigned int digit = number % 10;

        switch (colour) {
            case 'R':   result = (isDigitRed    (digit, flag) ? (result * 10 + digit) : result);    break;
            case 'B':   result = (isDigitBlack  (digit, flag) ? (result * 10 + digit) : result);    break;
        }

        number = number / 10; flag = !flag;
    }

    return reversedNumber(result);
}

int isPalindrome(unsigned int number) {
    unsigned int temporary  =   number;
    unsigned int reversed   =   0;

    while (number > 0) {
        unsigned int digit = number % 10;
        number = number / 10;
        reversed = reversed * 10 + digit;
    }

    return temporary == reversed;
}

int calculateNumberRedDigits(unsigned int number) {
    unsigned int result = 0;
    unsigned int digits = countDigits(number);
    
    int flag = digits % 2;

    while (number > 0) {
        unsigned int digit = number % 2;
        result = result + (isDigitRed(digit, flag));
        number = number / 10; flag = !flag;
    }

    return result % 2 == 0;
}

int calculateNumberBlackDigits(unsigned int number) {
    unsigned int result = 0;
    unsigned int digits = countDigits(number);

    int flag = digits % 2;

    while (number > 0) {
        unsigned int digit = number % 2;
        result = result + (isDigitBlack(digit, flag));
        number = number / 10; flag = !flag;
    }

    return result % 2 == 1;
}

void printInformationNumbers(unsigned int number) {
    unsigned int number1    =   buildNumber(number, 'R');
    unsigned int number2    =   buildNumber(number, 'B');

    putchar('\n'); putchar('\n'); putchar('\n');

    printf("Information about the RED   number %u: \n", number1);
    printf("Number is a palindrome:         %s\n",  isPalindrome(number1)               ? "Yes" : "No");
    printf("Number has EVEN RED digits:     %s\n",  calculateNumberRedDigits(number1)   ? "Yes" : "No");
    printf("Number has ODD BLACK digits:    %s\n",  calculateNumberBlackDigits(number1) ? "Yes" : "No");

    putchar('\n'); putchar('\n'); putchar('\n');

    printf("Information about the BLACK number %u: \n", number2);
    printf("Number is a palindrome:         %s\n",  isPalindrome(number2)               ? "Yes" : "No");
    printf("Number has EVEN RED digits:     %s\n",  calculateNumberRedDigits(number2)   ? "Yes" : "No");
    printf("Number has ODD BLACK digits:    %s\n",  calculateNumberBlackDigits(number2) ? "Yes" : "No");

    putchar('\n'); putchar('\n'); putchar('\n');
}
