#include <stdlib.h>

#include <stdio.h>



#define MAX_CAPACITY 200



void clearStandardInput();



double          readElem();
unsigned int    readSize();



void buildArray(        double array[], unsigned int size, double valueZero, double valueOne, double valueIncr);
void printArray(const   double array[], unsigned int size, double valueZero, double valueOne, double valueIncr);



int main() {
    double arrayValues[MAX_CAPACITY] = { 0 };

    printf("Enter the zero fund: ");    double valueZero    =   readElem();
    printf("Enter the deposit  : ");    double valueOne     =   readElem();
    printf("Enter the increase : ");    double valueIncr    =   readElem();
                                        unsigned int size   =   readSize();

    buildArray(arrayValues, size, valueZero, valueOne, valueIncr);
    printArray(arrayValues, size, valueZero, valueOne, valueIncr);
    
    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



double readElem() {
    double elem         =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%lf", &elem);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return elem;
}

unsigned int readSize() {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the number of periods: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX_CAPACITY);

    return size;
}



void buildArray(double array[], unsigned int size, double valueZero, double valueOne, double valueIncr) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < size; ++i) {
        double coefficient = 1;

        for (unsigned int j = 1; j <= i + 1; ++j) {
            coefficient = coefficient * (1 + valueIncr / 100);
        }

        double part1 = valueZero * coefficient;
        double part2 = valueOne  * (coefficient - 1) / ((1 + valueIncr / 100) - 1);

        array[i] = part1 + part2;
    }
}

void printArray(const double array[], unsigned int size, double valueZero, double valueOne, double valueIncr) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    putchar('\n');
    putchar('\n');
    putchar('\n');

    printf("The zero fund is: %.2lf\n", valueZero   );
    printf("The deposit   is: %.2lf\n", valueOne    );
    printf("The increase  is: %.2lf\n", valueIncr   );

    for (unsigned int i = 0; i < size; ++i) {
        printf("After %u periods the fund is: %.2lf\n", i + 1, array[i]);
    }
}
