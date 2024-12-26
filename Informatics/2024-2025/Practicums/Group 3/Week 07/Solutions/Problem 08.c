#include <stdlib.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



unsigned int    readElem();
unsigned int    readNumb();
unsigned int    readSize();



void inputArray(        unsigned int array[], unsigned int size);
void printArray(const   unsigned int array[], unsigned int size);



void findNumberTimes(const unsigned int array[], unsigned int size, unsigned int number);



int main() {
    unsigned int array[MAX_CAPACITY] = { 0 };

    unsigned int size   = readSize();
    unsigned int number = readNumb();

    inputArray(array, size);
    printArray(array, size);

    findNumberTimes(array, size, number);

    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readElem() {
    unsigned int elem   =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%u", &elem);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return elem;
}

unsigned int readNumb() {
    unsigned int numb   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the number: ");

        inputArgument = scanf("%u", &numb);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return numb;
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



void inputArray(unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const unsigned int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%u ", array[i]);
    }

    putchar('\n');
}



void findNumberTimes(const unsigned int array[], unsigned int size, unsigned int number) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    unsigned int index1 = -1;
    unsigned int index2 = -1;

    unsigned int timesN = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (array[i] == number) {
            timesN = timesN + 1;
            
            if (index1 == (unsigned int)(-1)) {
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

        printf("The start position of the found is: %u\n",  index1);
        printf("The final position of the found is: %u\n",  index2);
    }
}
