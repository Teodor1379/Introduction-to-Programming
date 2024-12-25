#include <stdlib.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();


unsigned int    readElem();
unsigned int    readSize();



void inputArray(        unsigned int array[], unsigned int size);
void printArray(const   unsigned int array[], unsigned int size);
int  equalArray(const   unsigned int array[], unsigned int size);



unsigned int findMinNumber1(const   unsigned int array[], unsigned int size);
unsigned int findMaxNumber1(const   unsigned int array[], unsigned int size);

unsigned int findMinNumber2(const   unsigned int array[], unsigned int size);
unsigned int findMaxNumber2(const   unsigned int array[], unsigned int size);



int main() {
    unsigned int array[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    printf("The MIN element 1 in the array is: %u\n", findMinNumber1(array, size));
    printf("The MAX element 1 in the array is: %u\n", findMaxNumber1(array, size));
    printf("The MIN element 2 in the array is: %u\n", findMinNumber2(array, size));
    printf("The MAX element 2 in the array is: %u\n", findMaxNumber2(array, size));

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
        printf("Invalid size for the array!");

        exit(EXIT_FAILURE);
    }

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%u ", array[i]);
    }

    putchar('\n');
}

int equalArray(const unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < size - 1; ++i) {
        if (array[i] != array[i + 1]) {
            return 0;
        }
    }

    return 1;
}



unsigned int findMinNumber1(const unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    unsigned int minNumber = array[0];

    for (unsigned int i = 1; i < size; ++i) {
        if (minNumber > array[i]) {
            minNumber = array[i];
        }
    }

    return minNumber;
}

unsigned int findMaxNumber1(const unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    unsigned int maxNumber = array[0];

    for (unsigned int i = 1; i < size; ++i) {
        if (maxNumber < array[i]) {
            maxNumber = array[i];
        }
    }

    return maxNumber;
}

unsigned int findMinNumber2(const unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }
    
    if (equalArray(array, size)) {
        return array[0];
    }

    unsigned int minIndex1 =  0 ;
    unsigned int minIndex2 = -1 ;

    for (unsigned int i = 1; i < size; ++i) {
        if (array[minIndex1] > array[i]) {
            minIndex2 = minIndex1;
            minIndex1 = i;
        }

        if (array[minIndex1] < array[i] && (minIndex2 == (unsigned int)(-1) || array[i] < array[minIndex2])) {
            minIndex2 = i;
        }
    }

    return array[minIndex2];
}

unsigned int findMaxNumber2(const unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    if (equalArray(array, size)) {
        return array[0];
    }

    unsigned int maxIndex1 =  0 ;
    unsigned int maxIndex2 = -1 ;

    for (unsigned int i = 1; i < size; ++i) {
        if (array[maxIndex1] < array[i]) {
            maxIndex2 = maxIndex1;
            maxIndex1 = i;
        }

        if (array[maxIndex1] > array[i] && (maxIndex2 == (unsigned int)(-1) || (array[i] > array[maxIndex2]))) {
            maxIndex2 = i;
        }
    }

    return array[maxIndex2];
} 
