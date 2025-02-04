#include <assert.h>

#include <stdio.h>

#include <stdlib.h>



void clearStandardInput();



int             readElem(                   );
unsigned int    readSize(                   );
unsigned int    readTake(unsigned int size  );



int* buildArray(                    unsigned int size   );
int* duplcArray(const   int* array, unsigned int size   );
void clearArray(        int** array                     );

void inputArray(        int* array, unsigned int size   );
void printArray(const   int* array, unsigned int size   );



void printPermutation   (const int* array, const int* result, unsigned int size                     );
void printVariation     (const int* array, const int* result, unsigned int size1, unsigned int size2);
void printCombination   (const int* array, const int* result, unsigned int size1, unsigned int size2);

void generatePermutationsHelper (const int* array, int* result,             unsigned int size,                          unsigned int index                      );
void generateVariationsHelper   (const int* array, int* result, int* used,  unsigned int size, unsigned int subsize,    unsigned int index                      );
void generateCombinationsHelper (const int* array, int* result,             unsigned int size, unsigned int subsize,    unsigned int index1, unsigned int index2);

void generatePermutations   (const int* array, unsigned int size                        );
void generateVariations     (const int* array, unsigned int size, unsigned int subsize  );
void generateCombinations   (const int* array, unsigned int size, unsigned int subsize  );

void generatePermutationsScenario   (const int* array, unsigned int size);
void generateVariationsScenario     (const int* array, unsigned int size);
void generateCombinationsScenario   (const int* array, unsigned int size);



void swap(int* a, int* b);



int main() {
    unsigned int size = readSize();


    int* array = buildArray(size);

    if (array == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    printf("\n\n\n");   generatePermutationsScenario    (array, size);  printf("\n\n\n");
    printf("\n\n\n");   generateVariationsScenario      (array, size);  printf("\n\n\n");
    printf("\n\n\n");   generateCombinationsScenario    (array, size);  printf("\n\n\n");


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

unsigned int readTake(unsigned int size) {
    unsigned int take   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the number of taken elements: ");

        inputArgument = scanf("%u", &take);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || take > size);

    return take;
}



int* buildArray(unsigned int size) {
    assert(size !=  0);
    
    int* array = (int*)(malloc(size * sizeof(int)));

    if (array != NULL) {
        inputArray(array, size);
        printArray(array, size);
    }

    return array;
}

int* duplcArray(const int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    int* result = (int*)(malloc(size * sizeof(int)));

    if (result != NULL) {
        for (unsigned int i = 0; i < size; ++i) {
            result[i] = array[i];
        }
    }

    return result;
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

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}



void printPermutation(const int* array, const int* result, unsigned int size) {
    assert(array    !=  NULL);
    assert(result   !=  NULL);
    assert(size     !=  0   );

    printf("A permutation of the array ");

    putchar('[');

    for (unsigned int i = 0; i < size; ++i) {
        if (i < size - 1) {
            printf("%d, ", array[i]);
        } else {
            printf("%d", array[i]);
        }
    }

    putchar(']');

    printf(": ");

    putchar('[');

    for (unsigned int i = 0; i < size; ++i) {
        if (i < size - 1) {
            printf("%d, ", result[i]);
        } else {
            printf("%d", result[i]);
        }
    }

    putchar(']');

    putchar('\n');
}

void printVariation(const int* array, const int* result, unsigned int size1, unsigned int size2) {
    assert(array    !=  NULL);
    assert(result   !=  NULL);
    assert(size1    !=  0   );
    assert(size2    !=  0   );

    printf("A variation of the array ");

    putchar('[');

    for (unsigned int i = 0; i < size1; ++i) {
        if (i < size1 - 1) {
            printf("%d, ", array[i]);
        } else {
            printf("%d", array[i]);
        }
    }

    putchar(']');

    printf(": ");

    putchar('[');

    for (unsigned int i = 0; i < size2; ++i) {
        if (i < size2 - 1) {
            printf("%d, ", result[i]);
        } else {
            printf("%d", result[i]);
        }
    }

    putchar(']');

    putchar('\n');
}

void printCombination(const int* array, const int* result, unsigned int size1, unsigned int size2) {
    assert(array    !=  NULL);
    assert(result   !=  NULL);
    assert(size1    !=  0   );
    assert(size2    !=  0   );

    printf("A combination of the array ");

    putchar('[');

    for (unsigned int i = 0; i < size1; ++i) {
        if (i < size1 - 1) {
            printf("%d, ", array[i]);
        } else {
            printf("%d", array[i]);
        }
    }

    putchar(']');

    printf(": ");

    putchar('[');

    for (unsigned int i = 0; i < size2; ++i) {
        if (i < size2 - 1) {
            printf("%d, ", result[i]);
        } else {
            printf("%d", result[i]);
        }
    }

    putchar(']');

    putchar('\n');
}



void generatePermutationsHelper(const int* array, int* result, unsigned int size, unsigned int index) {
    assert(array    !=  NULL);
    assert(result   !=  NULL);
    assert(size     !=  0   );
    assert(index    <=  size);

    if (index == size) {
        printPermutation(array, result, size);

        return;
    }

    for (unsigned int i = index; i < size; ++i) {
        swap(&result[index], &result[i]);
        generatePermutationsHelper(array, result, size, index + 1);
        swap(&result[index], &result[i]);
    }
}

void generateVariationsHelper(const int* array, int* result, int* used, unsigned int size, unsigned int subsize, unsigned int index) {
    assert(array    !=  NULL);
    assert(result   !=  NULL);
    assert(used     !=  NULL);
    assert(size     !=  0   );
    assert(subsize  !=  0   );
    assert(index    <=  size);

    if (index == subsize) {
        printVariation(array, result, size, subsize);

        return;
    }

    for (unsigned int i = 0; i < size; ++i) {
        if (used[i] == 0) {
            result[index] =   array[i];

            used[i] = 1;

            generateVariationsHelper(array, result, used, size, subsize, index + 1);

            used[i] = 0;
        }
    }
}

void generateCombinationsHelper(const int* array, int* result, unsigned int size, unsigned int subsize, unsigned int index1, unsigned int index2) {
    assert(array    !=  NULL    );
    assert(result   !=  NULL    );
    assert(size     !=  0       );
    assert(subsize  !=  0       );
    assert(index1   <=  size    );
    assert(index2   <=  subsize );

    if (index2 == subsize) {
        printCombination(array, result, size, subsize);

        return;
    }

    if (index1 == size) {
        return;
    }

    generateCombinationsHelper(array, result, size, subsize, index1 + 1, index2     );

    result[index2] = array[index1];

    generateCombinationsHelper(array, result, size, subsize, index1 + 1, index2 + 1 );
}



void generatePermutations(const int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    int* duplicate = duplcArray(array, size);

    if (duplicate == NULL) {
        puts("Allocating Memory... ERROR!");

        return;
    }

    generatePermutationsHelper(array, duplicate, size, 0);

    clearArray(&duplicate);
}

void generateVariations(const int* array, unsigned int size, unsigned int subsize) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    int* result = (int*)(malloc(subsize * sizeof(int)));

    if (result == NULL) {
        puts("Allocating Memory... ERROR!");

        return;
    }

    int* used = (int*)(malloc(size * sizeof(int)));

    if (used == NULL) {
        puts("Allocating Memory... ERROR!");

        clearArray(&result);

        return;
    }

    for (unsigned int i = 0; i < size; ++i) {
        used[i] = 0;
    }

    generateVariationsHelper(array, result, used, size, subsize, 0);

    clearArray(&result  );
    clearArray(&used    );
}

void generateCombinations(const int* array, unsigned int size, unsigned int subsize) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    int* duplicate = (int*)(malloc(subsize * sizeof(int)));

    if (duplicate == NULL) {
        puts("Allocating Memory... ERROR!");

        return;
    }

    generateCombinationsHelper(array, duplicate, size, subsize, 0, 0);

    clearArray(&duplicate);
}



void generatePermutationsScenario(const int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    generatePermutations(array, size);
}

void generateVariationsScenario(const int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    unsigned int take = readTake(size);

    generateVariations(array, size, take);
}

void generateCombinationsScenario(const int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    unsigned int take = readTake(size);

    generateCombinations(array, size, take);
}



void swap(int* a, int* b) {
    assert(a    !=  NULL);
    assert(b    !=  NULL);

    int temp = 0;

    temp    =   *a  ;
    *a      =   *b  ;
    *b      =   temp;
}
