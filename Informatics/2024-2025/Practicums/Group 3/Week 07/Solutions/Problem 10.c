#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

#define MAX_CAPACITY 100

void inputArray(        unsigned int array[], size_t size);
void printArray(const   unsigned int array[], size_t size);

int isSequenceIncreasing(const unsigned int array[], size_t size);
int isSequenceDecreasing(const unsigned int array[], size_t size);

int isSequenceStrictlyIncreasing(const unsigned int array[], size_t size);
int isSequenceStrictlyDecreasing(const unsigned int array[], size_t size);

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

    printf("Is the sequence increasing: %s\n", isSequenceIncreasing(array, size) ? "Yes" : "No");
    printf("Is the sequence decreasing: %s\n", isSequenceDecreasing(array, size) ? "Yes" : "No");

    printf("Is the sequence strictly increasing: %s\n", isSequenceStrictlyIncreasing(array, size) ? "Yes" : "No");
    printf("Is the sequence strictly decreasing: %s\n", isSequenceStrictlyDecreasing(array, size) ? "Yes" : "No");

    return 0;
}

void inputArray(unsigned int array[], size_t size) {
    printf("Enter the elements of the array: ");

    for (size_t i = 0; i < size; ++i) {
        scanf("%u", &array[i]);
    }
}

void printArray(const unsigned int array[], size_t size) {
    printf("The elements of the array: ");

    for (size_t i = 0; i < size; ++i) {
        printf("%u ", array[i]);
    }

    putchar('\n');
}

int isSequenceIncreasing(const unsigned int array[], size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        if (array[i] <= array[i + 1]) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}

int isSequenceDecreasing(const unsigned int array[], size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        if (array[i] >= array[i + 1]) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}

int isSequenceStrictlyIncreasing(const unsigned int array[], size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        if (array[i] < array[i + 1]) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}

int isSequenceStrictlyDecreasing(const unsigned int array[], size_t size) {
    for (size_t i = 0; i < size - 1; ++i) {
        if (array[i] > array[i + 1]) {
            continue;
        } else {
            return 0;
        }
    }

    return 1;
}
