#include <stdlib.h>

#include <stdio.h> 



#define MAX_CAPACITY 100



void clearStandardInput();



unsigned int    readElem();
unsigned int    readOffs();
unsigned int    readSize();



void inputArray(        unsigned int array[], unsigned int size);
void printArray(const   unsigned int array[], unsigned int size);



void rotateArray(unsigned int array[], unsigned int size, unsigned int offset);



int main() {
    unsigned int array[MAX_CAPACITY] = { 100 };

    unsigned int size = readSize();
    unsigned int offs = readOffs();

    inputArray(array, size);
    printArray(array, size);

    rotateArray(array, size, offs);
    printArray(array, size);

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

unsigned int readOffs() {
    unsigned int offs   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the offset of the array: ");

        inputArgument = scanf("%u", &offs);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return offs;
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



void rotateArray(unsigned int array[], unsigned int size, unsigned int offset) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return;
    }

    unsigned int current = 0;

    while (current < (offset % size)) {
        unsigned int element = array[size - 1];

        for (unsigned int i = size - 1; i > 0; --i) {
            array[i] = array[i - 1];
        }

        array[0] = element;

        current = current + 1;
    }
}
