#include <assert.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);



int insertAtBeg(int array[], unsigned int* size, int element                    );
int insertAtEnd(int array[], unsigned int* size, int element                    );
int insertAtPos(int array[], unsigned int* size, int element, unsigned int pos  );



int main() {
    int array[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    if (insertAtBeg(array, &size, 1379))    { printArray(array, size);  }   else    { puts("Input in array error!");    return 1;   }
    if (insertAtEnd(array, &size, 1379))    { printArray(array, size);  }   else    { puts("Input in array error!");    return 1;   }

    if (insertAtPos(array, &size, 9731,    0))  { printArray(array, size);  }   else    { puts("Input in array error!");    return 1;   }
    if (insertAtPos(array, &size, 9731, size))  { printArray(array, size);  }   else    { puts("Input in array error!");    return 1;   }
    if (insertAtPos(array, &size,    0,    3))  { printArray(array, size);  }   else    { puts("Input in array error!");    return 1;   }

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
    } while (inputArgument != 1);

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



int insertAtBeg(int array[], unsigned int* size, int element) {
    assert(*size != 0           );
    assert(*size <= MAX_CAPACITY);

    if (*size == MAX_CAPACITY) {
        return 0;
    }

    for (unsigned int i = *size; i > 0; --i) {
        array[i] = array[i - 1];
    }

    array[0] = element;
    
    *size = *size + 1;

    return 1;
}

int insertAtEnd(int array[], unsigned int* size, int element) {
    assert(*size != 0           );
    assert(*size <= MAX_CAPACITY);

    if (*size == MAX_CAPACITY) {
        return 0;
    }

    array[*size] = element;

    *size = *size + 1;

    return 1;
}

int insertAtPos(int array[], unsigned int* size, int element, unsigned int pos) {
    assert(*size != 0           );
    assert(*size <= MAX_CAPACITY);

    if (*size == MAX_CAPACITY) {
        return 0;
    }

    if (pos == 0) {
        return insertAtBeg(array, size, element);
    } else if (pos == *size - 1) {
        return insertAtEnd(array, size, element);
    } else {
        for (unsigned int i = *size; i > pos; --i) {
            array[i] = array[i - 1];
        }

        array[pos] = element;

        *size = *size + 1;

        return 1;
    }
}
