#include <math.h>

#include <stdlib.h>

#include <stdio.h>



#define EPSILON      1e-9
#define MAX_CAPACITY 100



void clearStandardInput();



double          readElem();
unsigned int    readSize();



void inputArray(        double array[], unsigned int size);
void printArray(const   double array[], unsigned int size);



double findMin(const double array[], unsigned int size);
double findMax(const double array[], unsigned int size);



unsigned int countMinSame(const double array[], unsigned int size);
unsigned int countMaxSame(const double array[], unsigned int size);



int main() {
    double array[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    printf("The occurences of the MIN value in the array are: %u\n", countMinSame(array, size));
    printf("The occurences of the MAX value in the array are: %u\n", countMaxSame(array, size));

    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



double readElem() {
    double number       =   0;
    int inputArguments  =   0;

    do {
        inputArguments = scanf("%lf", &number);

        if (inputArguments != 1) {
            clearStandardInput();
        }
    } while (inputArguments != 1);

    return number;
}

unsigned int readSize() {
    unsigned int size   =   0;
    int inputArguments  =   0;

    do {
        printf("Enter the size of the array: ");

        inputArguments = scanf("%u", &size);

        if (inputArguments != 1) {
            clearStandardInput();
        }
    } while (inputArguments != 1 || size == 0 || size > MAX_CAPACITY);

    return size;
}



void inputArray(double array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const double array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%lf ", array[i]);
    }

    putchar('\n');
}



double findMin(const double array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    double minNumber = array[0];

    for (unsigned int i = 1; i < size; ++i) {
        if (minNumber > array[i]) {
            minNumber = array[i];
        }
    }

    return minNumber;
}

double findMax(const double array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    double maxNumber = array[0];

    for (unsigned int i = 1; i < size; ++i) {
        if (maxNumber < array[i]) {
            maxNumber = array[i];
        }
    }

    return maxNumber;
}



unsigned int countMinSame(const double array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    unsigned int    result  =   0;
    double          minNum  =   findMin(array, size);

    for (unsigned int i = 0; i < size; ++i) {
        if (fabs(array[i] - minNum) < EPSILON) {
            result = result + 1;
        }
    }

    return result;
}

unsigned int countMaxSame(const double array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    unsigned int    result  =   0;
    double          maxNum  =   findMax(array, size);

    for (unsigned int i = 0; i < size; ++i) {
        if (fabs(array[i] - maxNum) < EPSILON) {
           result = result + 1; 
        }
    }

    return result;
}
