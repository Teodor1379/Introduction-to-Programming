#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

#define MAX_CAPACITY 100

void inputArray(        unsigned int array[], size_t size);
void printArray(const   unsigned int array[], size_t size);
int  equalArray(const   unsigned int array[], size_t size);

unsigned int findMinNumber1(const   unsigned int array[], size_t size);
unsigned int findMaxNumber1(const   unsigned int array[], size_t size);

unsigned int findMinNumber2(const   unsigned int array[], size_t size);
unsigned int findMaxNumber2(const   unsigned int array[], size_t size);

int main() {
    unsigned int array[MAX_CAPACITY] = { 0 };

    size_t size = 0;

    do {
        printf("Enter the size of the array: ");

        scanf("%zu", &size);

        while (getchar() != '\n');
    } while (size == 0 || size > 100);

    inputArray(array, size);
    printArray(array, size);

    printf("The MIN element 1 in the array is: %u\n", findMinNumber1(array, size));
    printf("The MAX element 1 in the array is: %u\n", findMaxNumber1(array, size));
    printf("The MIN element 2 in the array is: %u\n", findMinNumber2(array, size));
    printf("The MAX element 2 in the array is: %u\n", findMaxNumber2(array, size));

    return 0;
}

void inputArray(unsigned int array[], size_t size) {
    if (size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return;
    }

    printf("Enter the elements of the array: ");

    for (size_t i = 0; i < size; ++i) {
        scanf("%u", &array[i]);
    }
}

int equalArray(const unsigned int array[], size_t size) {
    if (size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return 0;
    }

    for (size_t i = 0; i < size - 1; ++i) {
        if (array[i] != array[i + 1]) {
            return 0;
        }
    }

    return 1;
}

void printArray(const unsigned int array[], size_t size) {
    if (size > MAX_CAPACITY) {
        printf("Invalid size for the array!");

        return;
    }

    printf("The elements of the array are: ");

    for (size_t i = 0; i < size; ++i) {
        printf("%u ", array[i]);
    }

    putchar('\n');
}

unsigned int findMinNumber1(const unsigned int array[], size_t size) {
    if (size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    unsigned int minNumber = array[0];

    for (size_t i = 1; i < size; ++i) {
        if (minNumber > array[i]) {
            minNumber = array[i];
        }
    }

    return minNumber;
}

unsigned int findMaxNumber1(const unsigned int array[], size_t size) {
    if (size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return (unsigned int)(-1);
    }

    unsigned int maxNumber = array[0];

    for (size_t i = 1; i < size; ++i) {
        if (maxNumber < array[i]) {
            maxNumber = array[i];
        }
    }

    return maxNumber;
}

unsigned int findMinNumber2(const unsigned int array[], size_t size) {
    if (size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return (unsigned int)(-1);
    }
    
    if (equalArray(array, size)) {
        return array[0];
    }

    size_t minIndex1 = 0;
    size_t minIndex2 = -1;

    for (size_t i = 1; i < size; ++i) {
        if (array[minIndex1] > array[i]) {
            minIndex2 = minIndex1;
            minIndex1 = i;
        }

        int condition1 = (minIndex2 == (size_t)(-1));
        int condition2 = (array[i] < array[minIndex2]);

        if (array[minIndex1] < array[i] && (condition1 || condition2)) {
            minIndex2 = i;
        }
    }

    return array[minIndex2];
}

unsigned int findMaxNumber2(const unsigned int array[], size_t size) {
    if (size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return (unsigned int)(-1);
    }

    if (equalArray(array, size)) {
        return array[0];
    }

    size_t maxIndex1 = 0;
    size_t maxIndex2 = -1;

    for (size_t i = 1; i < size; ++i) {
        if (array[maxIndex1] < array[i]) {
            maxIndex2 = maxIndex1;
            maxIndex1 = i;
        }

        int condition1 = (maxIndex2 == (size_t)(-1));
        int condition2 = (array[i] > array[maxIndex2]);

        if (array[maxIndex1] > array[i] && (condition1 || condition2)) {
            maxIndex2 = i;
        }
    }

    return array[maxIndex2];
} 
