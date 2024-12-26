#include <assert.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);


void mergeArrays(const int array1[], const int array2[], int result[], unsigned int size1, unsigned int size2);



int main() {
    int array1[MAX_CAPACITY] = { 0 };
    int array2[MAX_CAPACITY] = { 0 };
    
    int array[2 * MAX_CAPACITY] = { 0 };
    
    printf("Enter the size of the array 1: ");  unsigned int size1 = readSize();
    printf("Enter the size of the array 2: ");  unsigned int size2 = readSize();

    inputArray(array1, size1);  printArray(array1, size1);
    inputArray(array2, size2);  printArray(array2, size2);

    mergeArrays(array1, array2, array, size1, size2);

    printArray(array, size1 + size2);

    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



int readElem() {
    int element         =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%d", &element);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return element;
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
        array[i] = readElem();
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



void mergeArrays(const int array1[], const int array2[], int result[], unsigned int size1, unsigned int size2) {
    assert(size1 != 0);
    assert(size2 != 0);
    assert(size1 <= MAX_CAPACITY);
    assert(size2 <= MAX_CAPACITY);


    unsigned int index1 = 0;
    unsigned int index2 = 0;
    unsigned int index3 = 0;


    while (index1 <= size1 - 1 && index2 <= size2 - 1) {
        if (array1[index1] < array2[index2]) {
            result[index3] = array1[index1];

            index1 = index1 + 1;
            index3 = index3 + 1;
        } else if (array1[index1] > array2[index2]) {
            result[index3] = array2[index2];

            index2 = index2 + 1;
            index3 = index3 + 1;
        } else {
            result[index3] = array1[index1];

            index1 = index1 + 1;
            index2 = index2 + 1;
            index3 = index3 + 1;
        }
    }

    while (index1 <= size1 - 1) {
        result[index3] = array1[index1];

        index1 = index1 + 1;
        index3 = index3 + 1;
    }

    while (index2 <= size2 - 1) {
        result[index3] = array2[index2];

        index2 = index2 + 1;
        index3 = index3 + 1;
    }
}
