#include <stdlib.h>

#include <stdio.h>


#define MAX_CAPACITY 100



void clearStandardInput();



double          readElem();
int             readNumb();
unsigned int    readSize();



void buildArray(        double array[], unsigned int size, double valueZero, double valueIncr   );
void printArray(const   double array[], unsigned int size, double valueZero, double valueIncr   );



int main() {
    double arrayValues[MAX_CAPACITY] = { 0.0 };

    printf("Enter the zero fund: ");    double valueZero    =   readElem();
    printf("Enter the increase : ");    double valueIncr    =   readElem();
                                        unsigned int size   =   readSize();

    buildArray(arrayValues, size, valueZero, valueIncr);
    printArray(arrayValues, size, valueZero, valueIncr);

    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



double readElem() {
    double element      =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%lf", &element);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return element;
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



void buildArray(double array[], unsigned int size, double valueZero, double valueIncr) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = valueZero + valueZero * (valueIncr / 100.0) * (i + 1);
    }
}

void printArray(const double array[], unsigned int size, double valueZero, double valueIncr) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    putchar('\n');
    putchar('\n');
    putchar('\n');

    printf("The zero fund is: %.2lf\n", valueZero   );
    printf("The increase  is: %.2lf\n", valueIncr   );

    for (unsigned int i = 0; i < size; ++i) {
        printf("After %u periods the fund is: %.2lf\n", i + 1, array[i]);
    }
}