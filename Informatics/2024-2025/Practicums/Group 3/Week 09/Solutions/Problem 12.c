#include <assert.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);



void sortArray(int array[], unsigned int size);



void findSetsConjunction(const int array1[], const int array2[], unsigned int size1, unsigned int size2, int array[], unsigned int* size);
void findSetsDisjunction(const int array1[], const int array2[], unsigned int size1, unsigned int size2, int array[], unsigned int* size);
void findSetsDifference1(const int array1[], const int array2[], unsigned int size1, unsigned int size2, int array[], unsigned int* size);
void findSetsDifference2(const int array1[], const int array2[], unsigned int size1, unsigned int size2, int array[], unsigned int* size);



int main() {
    int array1[MAX_CAPACITY] = { 0 };
    int array2[MAX_CAPACITY] = { 0 };

    printf("Enter the size of the array 1: ");  unsigned int size1  =   readSize();
    printf("Enter the size of the array 2: ");  unsigned int size2  =   readSize();

    inputArray(array1, size1);
    printArray(array1, size1);

    inputArray(array2, size2);
    printArray(array2, size2);



    sortArray(array1, size1);
    sortArray(array2, size2);

    

    int result1[    MAX_CAPACITY]   =   { 0 };
    int result2[2 * MAX_CAPACITY]   =   { 0 };
    int result3[    MAX_CAPACITY]   =   { 0 };
    int result4[    MAX_CAPACITY]   =   { 0 };

    unsigned int sizeR1 = 0;
    unsigned int sizeR2 = 0;
    unsigned int sizeR3 = 0;
    unsigned int sizeR4 = 0;

    findSetsConjunction(array1, array2, size1, size2, result1, &sizeR1);
    findSetsDisjunction(array1, array2, size1, size2, result2, &sizeR2);
    findSetsDifference1(array1, array2, size1, size2, result3, &sizeR3);
    findSetsDifference2(array1, array2, size1, size2, result4, &sizeR4);

    if (sizeR1 != 0) { printArray(result1, sizeR1); }   else    { printf("The conjunction of the arrays is empty!\n");  }
    if (sizeR2 != 0) { printArray(result2, sizeR2); }   else    { printf("The disjunction of the arrays is empty!\n");  }
    if (sizeR3 != 0) { printArray(result3, sizeR3); }   else    { printf("The difference1 of the arrays is empty!\n");  }
    if (sizeR4 != 0) { printArray(result4, sizeR4); }   else    { printf("The difference2 of the arrays is empty!\n");  }


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
    assert(size != 0);
    assert(size <= MAX_CAPACITY);

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



void findSetsConjunction(const int array1[], const int array2[], unsigned int size1, unsigned int size2, int array[], unsigned int* size) {
    assert(size1 != 0           );
    assert(size2 != 0           );
    assert(size1 <= MAX_CAPACITY);
    assert(size2 <= MAX_CAPACITY);

    unsigned int index1 = 0;
    unsigned int index2 = 0;
    unsigned int index3 = 0;

    while (index1 < size1 && index2 < size2) {
        if (array1[index1] < array2[index2]) {
            index1 = index1 + 1;
        } else if (array1[index1] > array2[index2]) {
            index2 = index2 + 1;
        } else {
            array[index3] = array1[index1];

            index1 = index1 + 1;
            index2 = index2 + 1;
            index3 = index3 + 1;
        }
    }

    *size = index3;
}

void findSetsDisjunction(const int array1[], const int array2[], unsigned int size1, unsigned int size2, int array[], unsigned int* size) {
    assert(size1 != 0           );
    assert(size2 != 0           );
    assert(size1 <= MAX_CAPACITY);
    assert(size2 <= MAX_CAPACITY);

    unsigned int index1 = 0;
    unsigned int index2 = 0;
    unsigned int index3 = 0;

    while (index1 < size1 && index2 < size2) {
        if (array1[index1] < array2[index2]) {
            array[index3] = array1[index1];

            index1 = index1 + 1;
            index3 = index3 + 1;
        } else if (array1[index1] > array2[index2]) {
            array[index3] = array2[index2];

            index2 = index2 + 1;
            index3 = index3 + 1;
        } else {
            array[index3] = array1[index1];

            index1 = index1 + 1;
            index2 = index2 + 1;
            index3 = index3 + 1;
        }
    }

    while (index1 < size1) {
        array[index3] = array1[index1];

        index1 = index1 + 1;
        index3 = index3 + 1;
    }

    while (index2 < size2) {
        array[index3] = array2[index2];

        index2 = index2 + 1;
        index3 = index3 + 1;
    }

    *size = index3;
}

void findSetsDifference1(const int array1[], const int array2[], unsigned int size1, unsigned int size2, int array[], unsigned int* size) {
    assert(size1 != 0           );
    assert(size2 != 0           );
    assert(size1 <= MAX_CAPACITY);
    assert(size2 <= MAX_CAPACITY);

    unsigned int index1 = 0;
    unsigned int index2 = 0;
    unsigned int index3 = 0;

    while (index1 < size1 && index2 < size2) {
        if (array1[index1] < array2[index2]) {
            array[index3] = array1[index1];

            index1 = index1 + 1;
            index3 = index3 + 1;
        } else if (array1[index1] > array2[index2]) {
            index2 = index2 + 1;
        } else {
            index1 = index1 + 1;
            index2 = index2 + 1;
        }
    }

    while (index1 < size1) {
        array[index3] = array1[index1];

        index1 = index1 + 1;
        index3 = index3 + 1;
    }

    *size = index3;
}

void findSetsDifference2(const int array1[], const int array2[], unsigned int size1, unsigned int size2, int array[], unsigned int* size) {
    assert(size1 != 0           );
    assert(size2 != 0           );
    assert(size1 <= MAX_CAPACITY);
    assert(size2 <= MAX_CAPACITY);

    unsigned int index1 = 0;
    unsigned int index2 = 0;
    unsigned int index3 = 0;

    while (index1 < size1 && index2 < size2) {
        if (array1[index1] < array2[index2]) {
            index1 = index1 + 1;
        } else if (array1[index1] > array2[index2]) {
            array[index3] = array2[index2];

            index2 = index2 + 1;
            index3 = index3 + 1;
        } else {
            index1 = index1 + 1;
            index2 = index2 + 1;
        }
    }

    while (index2 < size2) {
        array[index3] = array2[index2];

        index2 = index2 + 1;
        index3 = index3 + 1;
    }

    *size = index3;
}
