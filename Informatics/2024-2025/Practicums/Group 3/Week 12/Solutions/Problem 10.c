#include <assert.h>

#include <stdio.h>

#include <stdlib.h>



void clearStandardInput();



int             readElem();
unsigned int    readSize();



int* buildArray(            unsigned int size   );
void clearArray(int** array                     );



void printVector        (const int* array, unsigned int size);
void printVectorSpecial (const int* array, unsigned int size);

void generateVectorsHelper          (int* array, unsigned int size, unsigned int index);
void generateVectorsSpecialHelper   (int* array, unsigned int size, unsigned int index);

void generateVectors        (int* array, unsigned int size);
void generateVectorsSpecial (int* array, unsigned int size);



int main() {
    unsigned int size = readSize();


    int* array = buildArray(size * 2);

    if (array == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    printf("\n\n\n");   generateVectors         (array, size * 2);  printf("\n\n\n");
    printf("\n\n\n");   generateVectorsSpecial  (array, size * 2);  printf("\n\n\n");


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
    assert(size != 0);
    
    int* array = (int*)(malloc(size * sizeof(int)));

    return array;
}

void clearArray(int** array) {
    assert(*array != NULL);

    free(*array);

    *array = NULL;
}



void printVector(const int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    printf("The normal vector is: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');

}

void printVectorSpecial(const int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    printf("The special vector is: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}



void generateVectorsHelper(int* array, unsigned int size, unsigned int index) {
    assert(array    !=  NULL);
    assert(size     !=  0   );
    assert(index    <=  size);

    if (index == size) {
        printVector(array, size);

        return;
    }

    array[index]    =   0;  generateVectorsHelper(array, size, index + 1);
    array[index]    =   1;  generateVectorsHelper(array, size, index + 1);
}

void generateVectorsSpecialHelper(int* array, unsigned int size, unsigned int index) {
    assert(array    !=  NULL);
    assert(size     !=  0   );
    assert(index    <=  size);

    if (index == size) {
        int sum1    =   0;
        int sum2    =   0;

        for (unsigned int i = 0; i < size; ++i) {
            sum1 = sum1 + ((i <  size / 2) ? array[i] : 0);
            sum2 = sum2 + ((i >= size / 2) ? array[i] : 0);
        }

        if (sum1 == sum2) {
            printVectorSpecial(array, size);
        }

        return;
    }

    array[index]    =   0;  generateVectorsSpecialHelper(array, size, index + 1);
    array[index]    =   1;  generateVectorsSpecialHelper(array, size, index + 1);
}



void generateVectors(int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    generateVectorsHelper(array, size, 0);
}

void generateVectorsSpecial(int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    generateVectorsSpecialHelper(array, size, 0);
}
