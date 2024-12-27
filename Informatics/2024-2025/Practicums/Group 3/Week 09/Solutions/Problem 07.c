#include <assert.h>

#include <limits.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);



unsigned int binarySearch(int array[], unsigned int size, int element);



int main() {
    int array[MAX_CAPACITY] = { 0 };

    printf("Enter the size of the array: ");

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    printf("Enter the element for search: ");

    int element = readElem();


    unsigned int pointer = binarySearch(array, size, element);

    if (pointer == UINT_MAX) {
        printf("The element is not in the array!\n");
    } else {
        printf("The element is at position: %u\n", pointer);
    }


    return 0;
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
        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX_CAPACITY);

    return size;
}



void inputArray(int array[], unsigned int size) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readSize();
    }
}

void printArray(const int array[], unsigned int size) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}



unsigned int binarySearch(int array[], unsigned int size, int element) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

    unsigned int indexL =   0       ;
    unsigned int indexR =   size    ;

    while (indexL < indexR) {
        unsigned int indexM = indexL + (indexR - indexL) / 2;

        printf("The current index is: %u\n", indexM);

        if (array[indexM] == element) {
            return indexM;
        }

        if (array[indexM] > element) {
            indexR = indexM + 0;
        } else {
            indexL = indexM + 1;
        }
    }

    return UINT_MAX;
}
