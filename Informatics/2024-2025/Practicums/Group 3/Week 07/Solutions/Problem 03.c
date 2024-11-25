#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

#define MAX_CAPACITY 100

void inputArray(        unsigned int array[], size_t size);
void printArray(const   unsigned int array[], size_t size);

void rotateArray(unsigned int array[], size_t size, size_t offset);

int main() {
    unsigned int array[MAX_CAPACITY] = { 100 };

    size_t size = 0;
    size_t offs = 0;

    do {
        printf("Enter the size of the array: ");

        scanf("%zu", &size);

        while (getchar() != '\n');
    } while (size == 0 || size > 100);

    inputArray(array, size);
    printArray(array, size);

    while (getchar() != '\n');

    printf("Enter the offset of the array: ");
    scanf("%zu", &offs);

    rotateArray(array, size, offs);
    printArray(array, size);

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

void rotateArray(unsigned int array[], size_t size, size_t offset) {
    size_t current = 0;

    while (current < (offset % size)) {
        unsigned int element = array[size - 1];

        for (size_t i = size - 1; i > 0; --i) {
            array[i] = array[i - 1];
        }

        array[0] = element;

        current = current + 1;
    }
}
