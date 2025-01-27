#include <assert.h>

#include <stdio.h>

#include <stdlib.h>



void clearStandardInput();



int             readElem();
unsigned int    readSize();



int* buildArray(                       unsigned int size);
void clearArray(        int**   array                   );



void inputArray(        int*    array, unsigned int size);
void printArray(const   int*    array, unsigned int size);



int sumArrayHelper      (const int* array, unsigned int size, unsigned int index);
int productArrayHelper  (const int* array, unsigned int size, unsigned int index);



int sumArray    (const int* array, unsigned int size);
int productArray(const int* array, unsigned int size);



int main() {
    unsigned int size = readSize();


    int* array = buildArray(size);

    if (array == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    int sum     =   sumArray    (array, size);
    int product =   productArray(array, size);

    printf("The sum     of the elements of the array is: %d\n", sum     );
    printf("The product of the elements of the array is: %d\n", product );


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

    printf("Enter the elements of the array are: ");

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



int sumArrayHelper(const int* array, unsigned int size, unsigned int index) {
    assert(array    !=  NULL);
    assert(size     !=  0   );
    assert(index    <=  size);

    if (index == size) {
        return 0;
    }

    return array[index] + sumArrayHelper(array, size, index + 1);
}

int productArrayHelper(const int* array, unsigned int size, unsigned int index) {
    assert(array    !=  NULL);
    assert(size     !=  0   );
    assert(index    <=  size);
    
    if (index == size) {
        return 1;
    }

    return array[index] * productArrayHelper(array, size, index + 1);
}



int sumArray(const int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    return sumArrayHelper(array, size, 0);
}

int productArray(const int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    return productArrayHelper(array, size, 0);
}
