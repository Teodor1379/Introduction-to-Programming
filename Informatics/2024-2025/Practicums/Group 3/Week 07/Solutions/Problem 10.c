#include <stdlib.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



unsigned int    readElem();
unsigned int    readSize();



void inputArray(        unsigned int array[], unsigned int size);
void printArray(const   unsigned int array[], unsigned int size);



int isSequenceIncreasing(const unsigned int array[], unsigned int size);
int isSequenceDecreasing(const unsigned int array[], unsigned int size);

int isSequenceStrictlyIncreasing(const unsigned int array[], unsigned int size);
int isSequenceStrictlyDecreasing(const unsigned int array[], unsigned int size);



int main() {
    unsigned int array[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();
    
    inputArray(array, size);
    printArray(array, size);

    printf("Is the sequence increasing: %s\n", isSequenceIncreasing(array, size) ? "Yes" : "No");
    printf("Is the sequence decreasing: %s\n", isSequenceDecreasing(array, size) ? "Yes" : "No");

    printf("Is the sequence strictly increasing: %s\n", isSequenceStrictlyIncreasing(array, size) ? "Yes" : "No");
    printf("Is the sequence strictly decreasing: %s\n", isSequenceStrictlyDecreasing(array, size) ? "Yes" : "No");

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
        scanf("%u", &array[i]);
    }
}

void printArray(const unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("The elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%u ", array[i]);
    }

    putchar('\n');
}



int isSequenceIncreasing(const unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }
    
    for (unsigned int i = 0; i < size - 1; ++i) {
        if (array[i] <= array[i + 1]) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}

int isSequenceDecreasing(const unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < size - 1; ++i) {
        if (array[i] >= array[i + 1]) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}


int isSequenceStrictlyIncreasing(const unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < size - 1; ++i) {
        if (array[i] < array[i + 1]) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}

int isSequenceStrictlyDecreasing(const unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}
