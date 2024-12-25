#include <stdlib.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);



void mapExample1(int array[], unsigned int size);
void mapExample2(int array[], unsigned int size);
void mapExample3(int array[], unsigned int size);



int main() {
    int array1[MAX_CAPACITY] = { 0 };
    int array2[MAX_CAPACITY] = { 0 };
    int array3[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();

    inputArray(array1, size);
    printArray(array1, size);

    inputArray(array2, size);
    printArray(array2, size);

    inputArray(array3, size);
    printArray(array3, size);

    mapExample1(array1, size);  printArray(array1, size);
    mapExample2(array2, size);  printArray(array2, size);
    mapExample3(array3, size);  printArray(array3, size);
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



int readElem() {
    int elem            =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%d", &elem);

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


void inputArray(int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}



void mapExample1(int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = array[i] * array[i];
    }
}

void mapExample2(int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = array[i] * array[i] * array[i];
    }
}

void mapExample3(int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }
    
    for (unsigned int i = 0; i < size; ++i) {
        if (array[i] >= 0) {
            array[i] = array[i] * ( 1);
        } else {
            array[i] = array[i] * (-1);
        }
    }
}
