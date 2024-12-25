#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

#define MAX_CAPACITY 100

void inputArray(        unsigned int array[], size_t size);
void printArray(const   unsigned int array[], size_t size);

void printPairs(const unsigned int array[], size_t size, unsigned int m);

int main() {
    unsigned int array[MAX_CAPACITY] = { 0 };

    size_t size = 0;

    do {
        printf("Enter the size: ");

        scanf("%zu", &size);

        while (getchar() != '\n');
    } while (size == 0 || size > MAX_CAPACITY);

    unsigned int m = 0;

    printf("Enter the sum: ");
    scanf("%u", &m);

    inputArray(array, size);
    printPairs(array, size, m);

    return 0;
}

void inputArray(unsigned int array[], size_t size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return;
    }

    for (size_t i = 0; i < size; ++i) {
        scanf("%u", &array[i]);
    }
}

void printArray(const unsigned int array[], size_t size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return;
    }

    for (size_t i = 0; i < size; ++i) {
        printf("%u ", array[i]);
    }

    putchar('\n');
}

void printPairs(const unsigned int array[], size_t size, unsigned int m) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return;
    }

    printf("All pairs are: ");
    
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = i + 1; j < size; ++j) {
            if (array[i] + array[j] == m) {
                printf("( %d %d ) ", array[i], array[j]);
            }
        }
    }

    putchar('\n');
}
