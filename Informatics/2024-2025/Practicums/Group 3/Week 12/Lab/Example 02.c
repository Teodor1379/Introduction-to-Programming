#include <stdio.h>



void clearStandardInput();



unsigned long long int readNumber();



unsigned long long int findSumIterative1(unsigned long long int number);
unsigned long long int findSumIterative2(unsigned long long int number);
unsigned long long int findSumIterative3(unsigned long long int number);

unsigned long long int findSumRecursive1(unsigned long long int number);
unsigned long long int findSumRecursive2(unsigned long long int number);
unsigned long long int findSumRecursive3(unsigned long long int number);

static inline unsigned long long int findSumFormulas1(unsigned long long int number) { return number * (number + 1) / 2;                            }
static inline unsigned long long int findSumFormulas2(unsigned long long int number) { return number * (number + 1) * (2 * number + 1) / 6;         }
static inline unsigned long long int findSumFormulas3(unsigned long long int number) { return number * (number + 1) * number * (number + 1) / 4;    }



int main() {
    unsigned long long int number = readNumber();


    unsigned long long int result1 = findSumIterative1(number);
    unsigned long long int result2 = findSumIterative2(number);
    unsigned long long int result3 = findSumIterative3(number);

    unsigned long long int result4 = findSumRecursive1(number);
    unsigned long long int result5 = findSumRecursive2(number);
    unsigned long long int result6 = findSumRecursive3(number);

    unsigned long long int result7 = findSumFormulas1(number);
    unsigned long long int result8 = findSumFormulas2(number);
    unsigned long long int result9 = findSumFormulas3(number);

    printf("The Result 1, 2, 3 are: %llu %llu %llu\n",  result1, result2, result3);
    printf("The Result 4, 5, 6 are: %llu %llu %llu\n",  result4, result5, result6);
    printf("The Result 7, 8, 9 are: %llu %llu %llu\n",  result7, result8, result9);


    return 0;
}



unsigned long long int findSumIterative1(unsigned long long int number) {
    unsigned long long int result = 0;

    for (unsigned long long int i = 1; i <= number; ++i) {
        result = result + i;
    }

    return result;
}

unsigned long long int findSumIterative2(unsigned long long int number) {
    unsigned long long int result = 0;

    for (unsigned long long int i = 1; i <= number; ++i) {
        result = result + i * i;
    }

    return result;
}

unsigned long long int findSumIterative3(unsigned long long int number) {
    unsigned long long int result = 0;

    for (unsigned long long int i = 1; i <= number; ++i) {
        result = result + i * i * i;
    }

    return result;
}

unsigned long long int findSumRecursive1(unsigned long long int number) {
    if (number == 0) {
        return 0;
    }

    return number + findSumRecursive1(number - 1);
}

unsigned long long int findSumRecursive2(unsigned long long int number) {
    if (number == 0) {
        return 0;
    }

    return number * number + findSumRecursive2(number - 1);
}

unsigned long long int findSumRecursive3(unsigned long long int number) {
    if (number == 0) {
        return 0;
    }

    return number * number * number + findSumRecursive3(number - 1);
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned long long int readNumber() {
    unsigned long long int number   =   0;
    int inputArgument               =   0;

    do {
        printf("Enter the number: ");

        inputArgument = scanf("%llu", &number);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return number;
}
