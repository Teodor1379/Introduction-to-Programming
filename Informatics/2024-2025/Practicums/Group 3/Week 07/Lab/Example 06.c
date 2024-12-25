#include <stdlib.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);



int accumulateExample1(const int array[], unsigned int size);
int accumulateExample2(const int array[], unsigned int size);
int accumulateExample3(const int array[], unsigned int size);
int accumulateExample4(const int array[], unsigned int size);



int main() {
    int array[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    printf("The sum     of the elements of the array is: %d\n", accumulateExample1(array, size));
    printf("The product of the elements of the array is: %d\n", accumulateExample2(array, size));
    printf("The min     of the elements of the array is: %d\n", accumulateExample3(array, size));
    printf("The max     of the elements of the array is: %d\n", accumulateExample4(array, size));
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



int readElem() {
    int elem            =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%d", &elem);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return elem;
}

unsigned int readSize() {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the size of the array: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX_CAPACITY);

    return size;
}



void inputArray(int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}



int accumulateExample1(const int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    int result = 0;

    for (unsigned int i = 0; i < size; ++i) {
        result = result + array[i];
    }

    return result;
}

int accumulateExample2(const int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    int result = 1;

    for (unsigned int i = 0; i < size; ++i) {
        result = result * array[i];
    }

    return result;
}

int accumulateExample3(const int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    int result = array[0];

    for (unsigned int i = 1; i < size; ++i) {
        if (result > array[i]) {
            result = array[i];
        }
    }

    return result;
}

int accumulateExample4(const int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    int result = array[0];

    for (unsigned int i = 1; i < size; ++i) {
        if (result < array[i]) {
            result = array[i];
        }
    }

    return result;
}
