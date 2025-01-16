#include <stdio.h>



#define MAX_SIZE 100



void clearStandardInput();



unsigned int readNumber();



unsigned long long int fibonacciRecursiveLinearHelper(unsigned int n, unsigned long long int a, unsigned long long int b);

unsigned long long int fibonacciIterative           (unsigned int number);
unsigned long long int fibonacciRecursiveNonLinear  (unsigned int number);
unsigned long long int fibonacciRecursiveLinear     (unsigned int number);
unsigned long long int fibonacciMemoization         (unsigned int number);



int main() {
    unsigned int number = readNumber();
    

    unsigned long long int result1 = fibonacciIterative         (number);
    unsigned long long int result2 = fibonacciRecursiveNonLinear(number);
    unsigned long long int result3 = fibonacciRecursiveLinear   (number);
    unsigned long long int result4 = fibonacciMemoization       (number);

    printf("The Result 1 is: %llu\n",   result1);
    printf("The Result 2 is: %llu\n",   result2);
    printf("The Result 3 is: %llu\n",   result3);
    printf("The Result 4 is: %llu\n",   result4);
    
    
    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readNumber() {
    unsigned int number =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the number: ");

        inputArgument = scanf("%u", &number);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return number;
}



unsigned long long int fibonacciIterative(unsigned int number) {
    unsigned long long int number1 = 0;
    unsigned long long int number2 = 1;
    unsigned long long int number3 = 1;

    for (unsigned i = 1; i <= number; ++i) {
        number3 = number1 + number2;

        number1 = number2;
        number2 = number3;
    }

    return number1;
}

unsigned long long int fibonacciRecursiveNonLinear(unsigned int number) {
    if (number == 0) {
        return 0;
    }

    if (number == 1) {
        return 1;
    }

    return  fibonacciRecursiveNonLinear(number - 1) +
            fibonacciRecursiveNonLinear(number - 2);
}

unsigned long long int fibonacciRecursiveLinearHelper(unsigned int n, unsigned long long int a, unsigned long long int b) {
    if (n == 0) {
        return a;
    }

    if (n == 1) {
        return b;
    }

    return  fibonacciRecursiveLinearHelper(n - 1, b, a + b);
}

unsigned long long int fibonacciRecursiveLinear(unsigned int number) {
    return fibonacciRecursiveLinearHelper(number, 0, 1);
}

unsigned long long int fibonacciMemoization(unsigned int number) {
    static unsigned long long int array[MAX_SIZE] = { 0 };

    if (array[number] != 0) {
        return array[number];
    }

    array[0] = 0;
    array[1] = 1;

    for (unsigned long long int i = 2; i <= number; ++i) {
        array[i] = array[i - 1] + array[i - 2];
    }

    return array[number];
}
