#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

#define MAX_CAPACITY 100

void inputArray(        unsigned int array[], size_t size);
void printArray(const   unsigned int array[], size_t size);

void findNumberTimes(const unsigned int array[], size_t size, unsigned int number);

int main() {
    unsigned int array[MAX_CAPACITY] = { 0 };

    size_t size = 0;

    do {
        printf("Enter the size of the array: ");

        scanf("%zu", &size);

        while (getchar() != '\n');
    } while (size == 0 || size > 100);

    unsigned int number = 0;

    printf("Enter the number: ");
    scanf("%u", &number);

    inputArray(array, size);
    printArray(array, size);

    findNumberTimes(array, size, number);

    return 0;
}

void inputArray(unsigned int array[], size_t size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return;
    }

    printf("Enter the elements of the array: ");

    for (size_t i = 0; i < size; ++i) {
        scanf("%u", &array[i]);
    }
}

void printArray(const unsigned int array[], size_t size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return;
    }

    printf("The elements of the array are: ");

    for (size_t i = 0; i < size; ++i) {
        printf("%u ", array[i]);
    }

    putchar('\n');
}

void findNumberTimes(const unsigned int array[], size_t size, unsigned int number) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        return;
    }

    size_t index1 = -1;
    size_t index2 = -1;

    unsigned int timesN = 0;

    for (size_t i = 0; i < size; ++i) {
        if (array[i] == number) {
            timesN = timesN + 1;
            
            if (index1 == (size_t)(-1)) {
                index1 = i;
                index2 = i;
            } else {
                index2 = i;
            }
        }
    }

    if (timesN == 0) {
        puts("The number was not found in the array!");
    } else {
        printf("The found was found %u times!\n", timesN);

        printf("The start position of the found is: %zu\n", index1);
        printf("The final position of the found is: %zu\n", index2);
    }
}
