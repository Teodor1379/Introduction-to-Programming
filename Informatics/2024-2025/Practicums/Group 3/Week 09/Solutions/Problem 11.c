#include <assert.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);



void sortArray(int array[], unsigned int size);



int equalArrays(int array1[], int array2[], unsigned int size1, unsigned int size2);



int main() {
    int array1[MAX_CAPACITY] = { 0 };
    int array2[MAX_CAPACITY] = { 0 };

    printf("Enter the size of the array 1: ");  unsigned int size1 = readSize();
    printf("Enter the size of the array 2: ");  unsigned int size2 = readSize();

    inputArray(array1, size1);
    printArray(array1, size1);

    inputArray(array2, size2);
    printArray(array2, size2);


    int result = equalArrays(array1, array2, size1, size2);

    printf("Are the arrays with same elements: %s\n", result ? "Yes" : "No");


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
    unsigned int size   =   9;
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



void sortArray(int array[], unsigned int size) {
    assert(size != 0               );
    assert(size <= MAX_CAPACITY    );

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



int equalArrays(int array1[], int array2[], unsigned int size1, unsigned int size2) {
    assert(size1 != 0           );
    assert(size2 != 0           );
    assert(size1 <= MAX_CAPACITY);
    assert(size2 <= MAX_CAPACITY);

    if (size1 != size2) {
        return 0;
    }

    sortArray(array1, size1);
    sortArray(array2, size2);

    unsigned int size = (size1 + size2) / 2;

    for (unsigned int i = 0; i < size; ++i) {
        if (array1[i] != array2[i]) {
            return 0;
        }
    }

    return 1;
}
