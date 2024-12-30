#include <assert.h>

#include <limits.h>

#include <stdlib.h>

#include <stdio.h>



void clearStandardInput();



int             readElem();
unsigned int    readSize();



int* buildArray(                    unsigned int size   );
void demolArray(        int* array                      );

void inputArray(        int* array, unsigned int size   );
void printArray(const   int* array, unsigned int size   );



unsigned int countElements(const int* array, unsigned int size);



int* filterArray(const int* array, unsigned int size, unsigned int* sizeClone);



int main() {
    unsigned int sizeArray  =   readSize()  ;
    unsigned int sizeClone  =   0           ;


    int* array = buildArray(sizeArray);

    if (array == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    int* clone = filterArray(array, sizeArray, &sizeClone);

    if (clone == NULL) {
        puts("Allocating Memory... ERROR!");

        demolArray(array);

        return 1;
    }

    printArray(clone, sizeClone);


    demolArray(array);
    demolArray(clone);


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
    assert(size     != 0    );

    int* array = (int*)(malloc(size * sizeof(int)));

    if (array != NULL) {
        inputArray(array, size);
        printArray(array, size);
    }

    return array;
}

void demolArray(int* array) {
    assert(array    != NULL );

    free(array);

    array = NULL;
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
    assert(array    != NULL );
    assert(size     != 0    );

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}



unsigned int countElements(const int* array, unsigned int size) {
    assert(array    != NULL );
    assert(size     != 0    );

    unsigned int result = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (array[i] % 2 == 1) {
            result = result + 1;
        }
    }

    return result;
}



int* filterArray(const int* array, unsigned int size, unsigned int* sizeClone) {
    assert(array    != NULL );
    assert(size     != 0    );

    unsigned int occur = countElements(array, size);

    if (occur == 0) {
        puts("The filtered array is empty!");

        return NULL;
    }

    int* clone = (int*)(malloc(occur * sizeof(int)));

    if (clone != NULL) {
        unsigned int index = 0;

        for (unsigned int i = 0; i < size; ++i) {
            if (array[i] % 2 == 1) {
                clone[index] = array[i];

                index = index + 1;
            }
        }

        *sizeClone = occur;
    }

    return clone;
}
