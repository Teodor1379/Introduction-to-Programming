#include <assert.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);



void sortArray(int array[], unsigned int size);



void removeDuplicates(int array[], unsigned int* size, int result[]);



int main() {
    int array1[MAX_CAPACITY] = { 0 };
    int array2[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();

    inputArray(array1, size);
    printArray(array1, size);
    
    removeDuplicates(array1, &size, array2);

    printArray(array2, size);

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
        printf("Enter the size of the array: ");

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



void sortArray(int array[], unsigned int size) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

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



void removeDuplicates(int array[], unsigned int* size, int result[]) {
    assert(*size != 0           );
    assert(*size <= MAX_CAPACITY);

    sortArray(array, *size);

    unsigned int index1 = 0;
    unsigned int index2 = 0;

    while (index1 < *size) {
        if (index2 == 0) {
            result[index2] = array[index1];

            index2 = index2 + 1;
            index1 = index1 + 1;
        } else {
            if (array[index1] == result[index2 - 1]) {
                index1 = index1 + 1;
            } else {
                result[index2] = array[index1];

                index1 = index1 + 1;
                index2 = index2 + 1;
            }
        }
    }

    *size = index2;
}
