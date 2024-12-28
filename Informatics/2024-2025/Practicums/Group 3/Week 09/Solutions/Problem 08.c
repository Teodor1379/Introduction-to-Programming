#include <assert.h>

#include <stdio.h>



#define MAX_CAPACITY 200



void clearStandardInput();



double          readElem();
unsigned int    readSize();



void inputArray(        double array[], unsigned int size);
void printArray(const   double array[], unsigned int size);



int insertAtBeg(double array[], unsigned int* size, double element                      );
int insertAtEnd(double array[], unsigned int* size, double element                      );
int insertAtPos(double array[], unsigned int* size, double element, unsigned int pos    );



void transformArray(double array[], unsigned int* size);



int main() {
    double array[MAX_CAPACITY] = { 0.0 };

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    transformArray(array, &size);

    printArray(array, size);
    
    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



double readElem() {
    double elem         =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%lf", &elem);

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
    } while (inputArgument != 1 || size == 0 || size > MAX_CAPACITY / 2);

    return size;
}



void inputArray(double array[], unsigned int size) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const double array[], unsigned int size) {
    assert(size != 0            );
    assert(size <= MAX_CAPACITY );

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%lf ", array[i]);
    }

    putchar('\n');
}



int insertAtBeg(double array[], unsigned int* size, double element) {
    assert(*size != 0);
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

int insertAtEnd(double array[], unsigned int* size, double element) {
    assert(*size != 0           );
    assert(*size <= MAX_CAPACITY);

    if (*size == MAX_CAPACITY) {
        return 0;
    }

    array[*size] = element;

    *size = *size + 1;

    return 1;
}

int insertAtPos(double array[], unsigned int* size, double element, unsigned int pos) {
    assert(*size != 0           );
    assert(*size <= MAX_CAPACITY);
    assert(pos <= *size         );

    if (*size == MAX_CAPACITY) {
        return 0;
    }

    if (pos == 0) {
        return insertAtBeg(array, size, element);
    } else if (pos == *size) {
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



void transformArray(double array[], unsigned int* size) {
    assert(*size != 0           );
    assert(*size <= MAX_CAPACITY);

    if (*size == 1) {
        return;
    }

    for (unsigned int i = 0; i < *size - 1; i += 2) {    
        double averageValue = (array[i] + array[i + 1]) / 2.0;

        int result = insertAtPos(array, size, averageValue, i + 1);

        if (result == 0) {
            puts("Internal Error!");

            return;
        }
    }
}
