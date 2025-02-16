#include <assert.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);



int removeAtBeg(int array[], unsigned int* size                     );
int removeAtEnd(int array[], unsigned int* size                     );
int removeAtPos(int array[], unsigned int* size, unsigned int pos   );



int main() {
    int array[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    if (removeAtBeg(array, &size))  { printArray(array, size);  }   else    { puts("Remove from array error!"); return 1;   }
    if (removeAtEnd(array, &size))  { printArray(array, size);  }   else    { puts("Remove from array error!"); return 1;   }

    if (removeAtPos(array, &size,        0))    { printArray(array, size);  }   else    { puts("Remove from array error!"); return 1;   }
    if (removeAtPos(array, &size, size - 1))    { printArray(array, size);  }   else    { puts("Remove from array error!"); return 1;   }
    if (removeAtPos(array, &size,        3))    { printArray(array, size);  }   else    { puts("Remove from array error!"); return 1;   }

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



int removeAtBeg(int array[], unsigned int* size) {
    assert(*size != 0           );
    assert(*size <= MAX_CAPACITY);

    for (unsigned int i = 1; i < *size; ++i) {
        array[i - 1] = array[i];
    }

    *size = *size - 1;

    return 1;
}

int removeAtEnd(int array[], unsigned int* size) {
    assert(*size != 0           );
    assert(*size <= MAX_CAPACITY);

    array[*size - 1] = 0;

    *size = *size - 1;

    return 1;
}

int removeAtPos(int array[], unsigned int* size, unsigned int pos) {
    assert(*size != 0           );
    assert(*size <= MAX_CAPACITY);
    assert(pos < *size          );

    if (pos == 0) {
        return removeAtBeg(array, size);
    } else if (pos == *size - 1) {
        return removeAtEnd(array, size);
    } else {
        for (unsigned int i = pos; i < *size - 1; ++i) {
            array[i] = array[i + 1];
        }

        *size = *size - 1;

        return 1;
    }
}
