#include <assert.h>

#include <stdio.h>


#define MAX_CAPACITY 100



void clearStandardInput();


int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);



void sortArray(int array[], unsigned int size);



int findDistance(int array[], unsigned int size);



int main() {
    int array[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    printf("The min distance is: %d\n", findDistance(array, size));

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
    for (unsigned int i = 0; i < size - 1; ++i) {
        for (unsigned int j = i + 1; j < size; ++j) {
            if (array[i] < array[j]) {
                int temp = 0;

                temp        =   array[i];
                array[i]    =   array[j];
                array[j]    =   temp    ;
            }
        }
    }
}



int findDistance(int array[], unsigned int size) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

    sortArray(array, size);

    if (size == 1) {
        return 0;
    }

    int result = array[0] - array[1];

    for (unsigned int i = 2; i < size; ++i) {
        if (result > array[i - 1] - array[i]) {
            result = array[i - 1] - array[i];
        }
    }

    return result;
}