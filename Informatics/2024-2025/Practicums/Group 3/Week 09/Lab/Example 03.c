#include <assert.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(int array[], unsigned int size);
void printArray(int array[], unsigned int size);



// Insertion Sort
void sortArray(int array[], unsigned int size);



int main() {
    int array[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    sortArray(array, size);

    printArray(array, size);
    
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

void printArray(int array[], unsigned int size) {
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

    for (unsigned int i = 1; i < size; ++i) {
        int keyElement = array[i]   ;
        unsigned int j = i - 1      ;

        while (array[j] >= keyElement) {
            array[j + 1] = array[j];
            j = j - 1;

            if (j > size) {
                // If j is int, the condition in the loop should be
                // j >= 0 && array[j] >= keyElement, without this if!

                break;
            }
        }

        array[j + 1] = keyElement;
    }
}
