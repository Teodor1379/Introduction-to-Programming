#include <assert.h>

#include <stdio.h>

#include <stdlib.h>



void clearStandardInput();



int             readElem();
unsigned int    readSize();



int* buildArray(            unsigned int size   );
void clearArray(int** array                     );

void inputArray(        int* array, unsigned int size);
void printArray(const   int* array, unsigned int size);



void printSubset(const int* set, const int* subset, unsigned int size, unsigned int subsize);

void generateSubsetsHelper(const int* set, int* subset, unsigned int size, unsigned int subsize, unsigned int index1, unsigned int index2);

void generateSubsets(const int* set, unsigned int size);



int main() {
    unsigned int size = readSize();


    int* array = buildArray(size);

    if (array == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    generateSubsets(array, size);


    clearArray(&array);


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
    } while (inputArgument != 1 || size == 0);

    return size;
}



int* buildArray(unsigned int size) {
    assert(size !=  0   );

    int* array = (int*)(malloc(size * sizeof(int)));

    if (array != NULL) {
        inputArray(array, size);
        printArray(array, size);
    }

    return array;
}

void clearArray(int** array) {
    assert(*array   !=  NULL);

    free(*array);

    *array = NULL;
}



void inputArray(int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    printf("The elements of the array are: ");

    for (unsigned int i = 0;  i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}



void printSubset(const int* set, const int* subset, unsigned int size, unsigned int subsize) {
    assert(set      !=  NULL);
    assert(subset   !=  NULL);
    assert(size     !=  0   );

    printf("A subset of the set ");

    putchar('[');

    for (unsigned int i = 0; i < size; ++i) {
        if (i < size - 1) {
            printf("%d, ", set[i]);
        } else {
            printf("%d", set[i]);
        }
    }

    putchar(']');

    printf(": ");

    putchar('[');

    for (unsigned int i = 0; i < subsize; ++i) {
        if (i < subsize - 1) {
            printf("%d, ", subset[i]);
        } else {
            printf("%d", subset[i]);
        }
    }

    putchar(']');

    putchar('\n');
}



void generateSubsetsHelper(const int* set, int* subset, unsigned int size, unsigned int subsize, unsigned int index1, unsigned int index2) {
    assert(set      !=  NULL);
    assert(subset   !=  NULL);
    assert(size     !=  0   );
    assert(index1   <=  size);
    assert(index2   <=  size);

    if (index1 == size) {
        printSubset(set, subset, size, subsize);

        return;
    }
    
    generateSubsetsHelper(set, subset, size, subsize,       index1 + 1, index2      );

    subset[index2] = set[index1];

    generateSubsetsHelper(set, subset, size, subsize + 1,   index1 + 1, index2 + 1  );
}



void generateSubsets(const int* set, unsigned int size) {
    assert(set  !=  NULL);
    assert(size !=  0   );

    int* result = (int*)(malloc(size * sizeof(int)));

    generateSubsetsHelper(set, result, size, 0, 0, 0);

    clearArray(&result);
}
