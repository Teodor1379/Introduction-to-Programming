#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

#define MAX_CAPACITY 100

void inputArray(        unsigned int array[], size_t size);
void printArray(const   unsigned int array[], size_t size);

void reverseArraySolution1(unsigned int array[], size_t size);
void reverseArraySolution2(unsigned int array[], size_t size);

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

    reverseArraySolution1(array, size); printArray(array, size);
    reverseArraySolution2(array, size); printArray(array, size);

    return 0;
}

void inputArray(unsigned int array[], size_t size) {
    printf("Enter the elements of the array: ");

    for (size_t i = 0; i < size; ++i) {
        scanf("%u", &array[i]);
    }
}

void printArray(const unsigned int array[], size_t size) {
    printf("The elements of the array are: ");

    for (size_t i = 0; i < size; ++i) {
        printf("%u ", array[i]);
    }

    putchar('\n');
}

void reverseArraySolution1(unsigned int array[], size_t size) {
    unsigned int temporary[MAX_CAPACITY] = { 0 };

    for (size_t i = 0; i < size; ++i) {
        temporary[size - i - 1] = array[i];
    }

    for (size_t i = 0; i < size; ++i) {
        array[i] = temporary[i];
    }
}

void reverseArraySolution2(unsigned int array[], size_t size) {
    for (size_t i = 0; i < size / 2; ++i) {
        unsigned int temporary = array[i];

        array[i] = array[size - i - 1];
        array[size - i - 1] = temporary;
    }
}
