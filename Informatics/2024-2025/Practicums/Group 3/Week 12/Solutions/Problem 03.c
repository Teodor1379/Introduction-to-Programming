#include <assert.h>

#include <stdio.h>

#include <stdlib.h>



void clearStandardInput();



int             readElem();
unsigned int    readSize();



int* buildArray(                    unsigned int size   );
int* duplcArray(const   int* array, unsigned int size   );
void clearArray(        int** array                     );



void inputArray(        int* array, unsigned int size   );
void printArray(const   int* array, unsigned int size   );



unsigned int countOddElements   (const int* array, unsigned int size);
unsigned int countEvenElements  (const int* array, unsigned int size);



unsigned int countOddElementsHelper (const int* array, unsigned int size, unsigned int index);
unsigned int countEvenElementsHelper(const int* array, unsigned int size, unsigned int index);



void transformArray2(int* array, unsigned int size);
void transformArray3(int* array, unsigned int size);



void transformArray2Helper(int* array, unsigned int size, unsigned int index);
void transformArray3Helper(int* array, unsigned int size, unsigned int index);



int main() {
    unsigned int size = readSize();


    int* array = buildArray(size);

    if (array == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    unsigned int counter1 = countOddElements    (array, size);
    unsigned int counter2 = countEvenElements   (array, size);

    printf("The number of ODD   numbers in the array is: %u\n", counter1);
    printf("The number of EVEN  numbers in the array is: %u\n", counter2);


    int* result1 = duplcArray(array, size);
    
    if (result1 == NULL) {
        puts("Allocating Memory... ERROR!"); 
        
        clearArray(&array);
        
        return 1;
    }

    int* result2 = duplcArray(array, size);
    
    if (result2 == NULL) { 
        puts("Allocating Memory... ERROR!");
        
        clearArray(&array)  ;
        clearArray(&result1);
        
        return 1;
    }

    transformArray2(result1, size);
    transformArray3(result2, size);

    printArray(result1, size);
    printArray(result2, size);


    clearArray(&array)  ;
    clearArray(&result1);
    clearArray(&result2);


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



unsigned int countOddElementsHelper(const int* array, unsigned int size, unsigned int index) {
    assert(array    !=  NULL);
    assert(size     !=  0   );
    assert(index    <=  size);

    if (index == size) {
        return 0;
    }

    return (array[index] % 2 == 1) + countOddElementsHelper(array, size, index + 1); 
}

unsigned int countEvenElementsHelper(const int* array, unsigned int size, unsigned int index) {
    assert(array    !=  NULL);
    assert(size     !=  0   );
    assert(index    <=  size);

    if (index == size) {
        return 0;
    }

    return (array[index] % 2 == 0) + countEvenElementsHelper(array, size, index + 1);
}



unsigned int countOddElements   (const int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    return countOddElementsHelper(array, size, 0);
}

unsigned int countEvenElements  (const int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    return countEvenElementsHelper(array, size, 0);
}



void transformArray2Helper(int* array, unsigned int size, unsigned int index) {
    assert(array    !=  NULL);
    assert(size     !=  0   );
    assert(index    <=  size);

    if (index == size) {
        return;
    }

    array[index] = array[index] * array[index];

    transformArray2Helper(array, size, index + 1);
}

void transformArray3Helper(int* array, unsigned int size, unsigned int index) {
    assert(array    !=  NULL);
    assert(size     !=  0   );
    assert(index    <=  size);

    if (index == size) {
        return;
    }

    array[index] = array[index] * array[index] * array[index];

    transformArray3Helper(array, size, index + 1);
}



void transformArray2(int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    transformArray2Helper(array, size, 0);
}

void transformArray3(int* array, unsigned int size) {
    assert(array    !=  NULL);
    assert(size     !=  0   );

    transformArray3Helper(array, size, 0);
}
