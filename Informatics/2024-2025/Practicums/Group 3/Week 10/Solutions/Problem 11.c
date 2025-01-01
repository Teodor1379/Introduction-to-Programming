#include <assert.h>

#include <limits.h>

#include <stdlib.h>

#include <stdio.h>



void clearStandardInput();



unsigned int    readElem();
unsigned int    readSize();



unsigned int*   buildArray(                                 unsigned int size   );
void            clearArray(         unsigned    int* array                      );

void            inputArray(         unsigned    int* array, unsigned int size   );
void            printArray(const    unsigned    int* array, unsigned int size   );



void sortArray(unsigned int* array, unsigned int size);



unsigned int* findElements(unsigned int* array, unsigned int oldSize, unsigned int* newSize);



int main() {
    unsigned int oldSize    =   readSize()  ;
    unsigned int newSize    =   0           ;


    unsigned int* array = buildArray(oldSize);

    if (array == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    unsigned int* elements = findElements(array, oldSize, &newSize);

    printArray(elements, newSize);


    clearArray(array);
    clearArray(elements);


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



unsigned int* buildArray(unsigned int size) {
    assert(size != 0);

    unsigned int* array = (unsigned int*)(malloc(size * sizeof(unsigned int)));

    if (array != NULL) {
        inputArray(array, size);
        printArray(array, size);
    }

    return array;
}

void clearArray(unsigned int* array) {
    assert(array != NULL);

    free(array);

    array = NULL;
}


void inputArray(unsigned int* array, unsigned int size) {
    assert(array    != NULL );
    assert(size     != 0    );

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const unsigned int* array, unsigned int size) {
    assert(array    != NULL );
    assert(size     != 0    );
    
    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}



void sortArray(unsigned int* array, unsigned int size) {
    assert(array    != NULL );
    assert(size     != 0    );

    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            if (array[i] > array[j]) {
                int temp = 0;

                temp        =   array[i];
                array[i]    =   array[j];
                array[j]    =   temp    ;
            }
        }
    }
}



unsigned int* findElements(unsigned int* array, unsigned int oldSize, unsigned int* newSize) {
    assert(array != NULL);

    assert(oldSize != 0);

    sortArray(array, oldSize);

    unsigned int size = 0;
    unsigned int indx = 0;

    unsigned int minNumber = array[0            ]   ;
    unsigned int maxNumber = array[oldSize - 1  ]   ;
    unsigned int curNumber = minNumber              ;

    while (curNumber <= maxNumber) {
        if (curNumber == array[indx]) {
            indx = indx + 1;
        } else {
            size = size + 1;   
        }

        curNumber = curNumber + 1;
    }

    unsigned int* result = (unsigned int*)(malloc(size * sizeof(unsigned int)));

    if (result != NULL) {
        unsigned int indx1 = 0;
        unsigned int indx2 = 0;

        curNumber = minNumber;

        while (curNumber <= maxNumber) {
            if (curNumber == array[indx1]) {
                indx1 = indx1 + 1;
            } else {
                result[indx2] = curNumber;

                indx2 = indx2 + 1;
            }

            curNumber = curNumber + 1;
        }

        *newSize = size;
    }

    return result;
}
