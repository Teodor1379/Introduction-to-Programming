#include <stdlib.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



unsigned int    readElem();
unsigned int    readSize();



void inputArray(        unsigned int array[], unsigned int size);
void printArray(const   unsigned int array[], unsigned int size);



void reverseArraySolution1(unsigned int array[], unsigned int size);
void reverseArraySolution2(unsigned int array[], unsigned int size);



int main() {
    unsigned int array[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    reverseArraySolution1(array, size); printArray(array, size);
    reverseArraySolution2(array, size); printArray(array, size);

    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readElem() {
    unsigned int elem   =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%u", &elem);

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
        printf("Enter the size of the array: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX_CAPACITY);

    return size;
}



void inputArray(unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%u ", array[i]);
    }

    putchar('\n');
}


void reverseArraySolution1(unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    unsigned int temporary[MAX_CAPACITY] = { 0 };

    for (unsigned int i = 0; i < size; ++i) {
        temporary[size - i - 1] = array[i];
    }

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = temporary[i];
    }
}

void reverseArraySolution2(unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }
    
    for (unsigned int i = 0; i < size / 2; ++i) {
        unsigned int temporary = array[i];

        array[i] = array[size - i - 1];
        array[size - i - 1] = temporary;
    }
}
