#include <math.h>

#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

#define EPSILON      1e-9
#define MAX_CAPACITY 100

void inputArray(        double array[], size_t size);
void printArray(const   double array[], size_t size);

double findMin(const double array[], size_t size);
double findMax(const double array[], size_t size);

unsigned int countMinSame(const double array[], size_t size);
unsigned int countMaxSame(const double array[], size_t size);

int main() {
    double array[MAX_CAPACITY] = { 0 };

    size_t size = 0;

    do {
        printf("Enter the size of the array: ");

        scanf("%zu", &size);

        while (getchar() != '\n');
    } while (size == 0 || size > 100);

    inputArray(array, size);
    printArray(array, size);

    printf("The occurences of the MIN value in the array are: %u\n", countMinSame(array, size));
    printf("The occurences of the MAX value in the array are: %u\n", countMaxSame(array, size));

    return 0;
}

void inputArray(double array[], size_t size) {
    printf("Enter the elements of the array: ");

    for (size_t i = 0; i < size; ++i) {
        scanf("%lf", &array[i]);
    }
}

void printArray(const double array[], size_t size) {
    printf("The elements of the array are: ");

    for (size_t i = 0; i < size; ++i) {
        printf("%lf ", array[i]);
    }

    putchar('\n');
}

double findMin(const double array[], size_t size) {
    double minNumber = array[0];

    for (size_t i = 1; i < size; ++i) {
        if (minNumber > array[i]) {
            minNumber = array[i];
        }
    }

    return minNumber;
}

double findMax(const double array[], size_t size) {
    double maxNumber = array[0];

    for (size_t i = 1; i < size; ++i) {
        if (maxNumber < array[i]) {
            maxNumber = array[i];
        }
    }

    return maxNumber;
}

unsigned int countMinSame(const double array[], size_t size) {
    unsigned int    result  =   0;
    double          minNum  =   findMin(array, size);

    for (size_t i = 0; i < size; ++i) {
        if (fabs(array[i] - minNum) < EPSILON) {
            result = result + 1;
        }
    }

    return result;
}

unsigned int countMaxSame(const double array[], size_t size) {
    unsigned int    result  =   0;
    double          maxNum  =   findMax(array, size);

    for (size_t i = 0; i < size; ++i) {
        if (fabs(array[i] - maxNum) < EPSILON) {
           result = result + 1; 
        }
    }

    return result;
}
