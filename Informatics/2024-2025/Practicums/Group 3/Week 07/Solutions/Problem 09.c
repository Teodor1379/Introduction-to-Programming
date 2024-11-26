#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

#define MAX_CAPACITY 100

void inputArray(        unsigned int array[], size_t size);
void printArray(const   unsigned int array[], size_t size);

void findSubArrayMin(const unsigned int array[], size_t size);
void findSubArrayMax(const unsigned int array[], size_t size);

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

    findSubArrayMin(array, size);
    findSubArrayMax(array, size);

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

void printArray(const unsigned int array[], size_t size) {
    if (size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return;
    }

    printf("The elements of the array are: ");

    for (size_t i = 0; i < size; ++i) {
        printf("%u ", array[i]);
    }

    putchar('\n');
}

void findSubArrayMin(const unsigned int array[], size_t size) {
    if (size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return;
    }

    size_t maxStart = 0;
    size_t maxFinal = 0;

    size_t maxLength = 0;
    size_t curLength = 0;

    size_t current = 0;

    for (size_t i = 1; i < size; ++i) {
        if (array[i - 1] >= array[i]) {
            curLength = curLength + 1;
        } else {
            if (curLength > maxLength) {
                maxLength   =   curLength;

                maxStart    =   current;
                maxFinal    =   i - 1;
            }

            current     =   i;
            curLength   =   1;
        }
    }

    if (curLength > maxLength) {
        maxLength   =   curLength;

        maxStart    =   current;
        maxFinal    =   size - 1;
    }

    printf("The MAX start index is: %zu\n", maxStart);
    printf("The MAX final index is: %zu\n", maxFinal);
}

void findSubArrayMax(const unsigned int array[], size_t size) {
    if (size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return;
    }
    
    size_t maxStart = 0;
    size_t maxFinal = 0;

    size_t maxLength = 0;
    size_t curLength = 0;

    size_t current = 0;

    for (size_t i = 1; i < size; ++i) {
        if (array[i - 1] <= array[i]) {
            curLength = curLength + 1;
        } else {
            if (curLength > maxLength) {
                maxLength   =   curLength;

                maxStart    =   current;
                maxFinal    =   i - 1;
            }

            current     =   i;
            curLength   =   1;
        }
    }

    if (curLength > maxLength) {
        maxLength   =   curLength;

        maxStart    =   current;
        maxFinal    =   size - 1;
    }

    printf("The MAX start index is: %zu\n", maxStart);
    printf("The MAX final index is: %zu\n", maxFinal);
}
