#include <assert.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);



int* linearSearch(int array[], unsigned int size, int element);
int* binarySearch(int array[], unsigned int size, int element);



void intervalSearch(int array[], unsigned int size, int element, int** start, int** final);



int main() {
    int array[MAX_CAPACITY] = { 0 };

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);


    int* pointer1   =   linearSearch(array, size, 9);
    int* pointer2   =   binarySearch(array, size, 7);

    if (pointer1 == NULL) {
        printf("The element is not in the array!\n");
    } else {
        printf("The element is at position: %ld\n", pointer1 - array);
    }

    if (pointer2 == NULL) {
        printf("The element is not in the array!\n");
    } else {
        printf("The element is at position: %ld\n", pointer2 - array);
    }


    int* start = NULL;
    int* final = NULL;

    intervalSearch(array, size, 3, &start, &final);


    if (start == NULL && final == NULL) {
        printf("There is not such range!\n");
    } else {
        printf("The start pointer value is: %d\n", *start);
        printf("The final pointer value is: %d\n", *final);
    }


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

    const int* const startPointer = array       ;
    const int* const finalPointer = array + size;

    printf("The elements of the array are: ");

    for (const int* current = startPointer; current < finalPointer; ++current) {
        printf("%d ", *current);
    }

    putchar('\n');
}



int* linearSearch(int array[], unsigned int size, int element) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );
    
    int* pointerCurrent = array;

    while (pointerCurrent <= array + size) {
        if (*pointerCurrent == element) {
            return pointerCurrent;
        }

        pointerCurrent++;
    }

    return NULL;
}

int* binarySearch(int array[], unsigned int size, int element) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

    int* pointerLeft    =   array       ;
    int* pointerRight   =   array + size;

    while (pointerLeft < pointerRight) {
        int* pointerMiddle = pointerLeft + (pointerRight - pointerLeft) / 2;

        if (*pointerMiddle == element) {
            return pointerMiddle;
        }

        if (*pointerMiddle > element) {
            pointerRight = pointerMiddle;
        } else {
            pointerLeft = pointerMiddle + 1;
        }
    }

    return NULL;
}



void intervalSearch(int array[], unsigned int size, int element, int** start, int** final) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

    int* pointer1   =   array       ;
    int* pointer2   =   array + size;

    while (pointer1 < pointer2) {
        int* middle = pointer1 + (pointer2 - pointer1) / 2;

        if (*middle >= element) {
            pointer2 = middle;
        } else {
            pointer1 = middle + 1;
        }
    }

    if (*pointer1 != element) {
        return;
    }

    *start  =   pointer1        ;

    pointer2 = array + size;

    while (pointer1 < pointer2) {
        int* middle = pointer1 + (pointer2 - pointer1) / 2;

        if (*middle > element) {
            pointer2 = middle;
        } else {
            pointer1 = middle + 1;
        }
    }

    *final  =   pointer1        ;
}
