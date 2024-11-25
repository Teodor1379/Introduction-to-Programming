#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

#define MAX_CAPACITY 100

void inputArray(        unsigned int array[], size_t size);
void printArray(const   unsigned int array[], size_t size);

void findMode(const unsigned int array[], size_t size);

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

    findMode(array, size);

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

void findMode(const unsigned int array[], size_t size) {
    unsigned int maxCounter = 0;
    unsigned int indNumber  = 0;

    for (size_t i = 0; i < size; ++i) {
        unsigned int currentT = 1;

        for (size_t j = i + 1; j < size; ++j) {
            if (array[j] == array[i]) {
                currentT = currentT + 1;
            }
        }

        if (maxCounter < currentT) {
            maxCounter  =   currentT;
            indNumber   =   i;
        }
    }

    printf("The mode of the array is:       %u\n",  array[indNumber]);
    printf("The number of occurences are:   %u\n",  maxCounter      );
}
