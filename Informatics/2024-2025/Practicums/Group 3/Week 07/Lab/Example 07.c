#include <stdlib.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);



unsigned int filterExample1(const int array[], unsigned int size, int result[]);
unsigned int filterExample2(const int array[], unsigned int size, int result[]);



int main() {
    int array[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    int result1[MAX_CAPACITY] = { 0 };  unsigned int size1 = filterExample1(array, size, result1);
    int result2[MAX_CAPACITY] = { 0 };  unsigned int size2 = filterExample2(array, size, result2);

    printf("Filtering the even...\n");  printArray(result1, size1);
    printf("Filtering the odd ...\n");  printArray(result2, size2);

    return 0;
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
        printf("%u ", array[i]);
    }

    putchar('\n');
}



unsigned int filterExample1(const int array[], unsigned int size, int result[]) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    unsigned int counter = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (array[i] % 2 == 0) {
            result[counter] = array[i];

            counter = counter + 1;
        }
    }

    return counter;
}

unsigned int filterExample2(const int array[], unsigned int size, int result[]) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    unsigned int counter = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (array[i] % 2 == 1) {
            result[counter] = array[i];

            counter = counter + 1;
        }
    }

    return counter;
}
