#include <assert.h>

#include <stdio.h>



#define MAX_SIZE1 100
#define MAX_SIZE2 100
#define MAX_SIZE3 100



void clearStandardInput();



int             readElem(                                   );
unsigned int    readSize(unsigned int MAX, const char* name );



void inputTensor(       int tensor[MAX_SIZE1][MAX_SIZE2][MAX_SIZE3], unsigned int size1, unsigned int size2, unsigned int size3);
void printTensor(const  int tensor[MAX_SIZE1][MAX_SIZE2][MAX_SIZE3], unsigned int size1, unsigned int size2, unsigned int size3);



int main() {
    int tensor[MAX_SIZE1][MAX_SIZE2][MAX_SIZE3] = { { { 0 } } };

    unsigned int size1  =   readSize(MAX_SIZE1, "SIZE1");
    unsigned int size2  =   readSize(MAX_SIZE2, "SIZE2");
    unsigned int size3  =   readSize(MAX_SIZE3, "SIZE3");

    inputTensor(tensor, size1, size2, size3);
    printTensor(tensor, size1, size2, size3);

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

unsigned int readSize(unsigned int MAX, const char* name) {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the %s size of the tensor: ", name);

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX);

    return size;
}



void inputTensor(int tensor[MAX_SIZE1][MAX_SIZE2][MAX_SIZE3], unsigned int size1, unsigned int size2, unsigned int size3) {
    assert(size1 != 0 && size1 <= MAX_SIZE1);
    assert(size2 != 0 && size2 <= MAX_SIZE2);
    assert(size3 != 0 && size3 <= MAX_SIZE3);

    printf("Enter the elements of the tensor:\n");

    for (unsigned int i = 0; i < size1; ++i) {
        for (unsigned int j = 0; j < size2; ++j) {
            for (unsigned int k = 0; k < size3; ++k) {
                tensor[i][j][k] = readElem();
            }
        }
    }
}

void printTensor(const int tensor[MAX_SIZE1][MAX_SIZE2][MAX_SIZE3], unsigned int size1, unsigned int size2, unsigned int size3) {
    assert(size1 != 0 && size1 <= MAX_SIZE1 );
    assert(size2 != 0 && size2 <= MAX_SIZE2 );
    assert(size3 != 0 && size3 <= MAX_SIZE3 );

    printf("The elements of the tensor are:\n");

    for (unsigned int i = 0; i < size1; ++i) {
        for (unsigned int j = 0; j < size2; ++j) {
            for (unsigned int k = 0; k < size3; ++k) {
                printf("%d ", tensor[i][j][k]);
            }

            putchar('\n');
        }

        putchar('\n');
    }
}



// warning: invalid use of pointers to arrays with different qualifiers in ISO C before C2X [-Wpedantic]
