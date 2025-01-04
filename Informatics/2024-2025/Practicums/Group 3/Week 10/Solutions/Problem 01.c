#include <assert.h>

#include <limits.h>

#include <stdlib.h>

#include <stdio.h>



void clearStandardInput();



int             readElem();
unsigned int    readSize();



int* buildArray(                    unsigned int size   );
int* cloneArray(const   int* array, unsigned int size   );
void clearArray(        int** array                     );

void inputArray(        int* array, unsigned int size   );
void printArray(const   int* array, unsigned int size   );



int main() {
    unsigned int size = readSize();


    int* array = buildArray(size);

    if (array == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    int* clone = cloneArray(array, size);

    if (clone == NULL) {
        puts("Allocating Memory... ERROR!");

        clearArray(&array);

        return 1;
    }


    printArray(clone, size);


    clearArray(&array);
    clearArray(&clone);


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
        printf("Enter the size of the array: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > UINT_MAX);

    return size;
}



int* buildArray(unsigned int size) {
    assert(size     !=  0   );

    int* array = (int*)(malloc(size * sizeof(int)));

    if (array != NULL) {
        inputArray(array, size);
        printArray(array, size);
    }

    return array;
}

int* cloneArray(const int* array, unsigned int size) {
    assert(array    !=  NULL    );
    assert(size     !=  0       );

    int* clone = malloc(size * sizeof(int));

    if (clone != NULL) {
        for (unsigned int i = 0; i < size; ++i) {
            clone[i] = array[i];
        }
    }

    return clone;
}

void clearArray(int** array) {
    assert(*array    != NULL );

    free(*array);

    *array = NULL;
}


void inputArray(int* array, unsigned int size) {
    assert(array    != NULL );
    assert(size     != 0    );

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
    
}

void printArray(const int* array, unsigned int size) {
    assert(array    !=  NULL    );
    assert(size     !=  0       );

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}
