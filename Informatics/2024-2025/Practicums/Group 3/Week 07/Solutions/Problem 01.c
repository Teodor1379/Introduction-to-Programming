#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

#define MAX_CAPACITY 100

void inputArray(        unsigned int array[], size_t size);
void printArray(const   unsigned int array[], size_t size);

void findSumProduct(const   unsigned int array[], size_t size);

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

    findSumProduct(array, size);

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

void findSumProduct(const unsigned int array[], size_t size) {
    if (size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return;
    }

    unsigned int result1 = 0;
    unsigned int result2 = 1;

    for (size_t i = 0; i < size; ++i) {
        result1 = result1 + array[i];
        result2 = result2 * array[i];
    }

    printf("The sum     of the elements of the array is: %u\n", result1);
    printf("The product of the elements of the array is: %u\n", result2);
}
