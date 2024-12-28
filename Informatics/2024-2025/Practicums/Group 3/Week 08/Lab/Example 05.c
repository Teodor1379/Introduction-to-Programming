#include <assert.h>

#include <stdio.h>



#define MAX_SIZE1 100
#define MAX_SIZE2 100



void clearStandardInput();



int             readElem(                                   );
unsigned int    readSize(unsigned int MAX, const char* name );



int validateSize(unsigned int MAX, unsigned int size);



void inputMatrix(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2);
void printMatrix(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2);



int main() {
    int matrix[MAX_SIZE1][MAX_SIZE2] = { { 0 } };

    unsigned int size1 = readSize(MAX_SIZE1, "ROWS");
    unsigned int size2 = readSize(MAX_SIZE2, "COLS");

    inputMatrix(matrix, size1, size2);
    printMatrix(matrix, size1, size2);

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
        printf("Enter the %s size of the matrix: ", name);

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX);

    return size;
}



int validateSize(unsigned int MAX, unsigned int size) {
    return size != 0 && size <= MAX;
}



void inputMatrix(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2) {
    assert(validateSize(MAX_SIZE1, size1)   );
    assert(validateSize(MAX_SIZE2, size2)   );

    printf("Enter the elements of the matrix:\n");

    for (unsigned int i = 0; i < size1; ++i) {
        for (unsigned int j = 0; j < size2; ++j) {
            matrix[i][j] = readElem();
        }
    }
}

void printMatrix(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2) {
    assert(validateSize(MAX_SIZE1, size1)   );
    assert(validateSize(MAX_SIZE2, size2)   );

    printf("The elements of the matrix are:\n");

    for (unsigned int i = 0; i < size1; ++i) {
        for (unsigned int j = 0; j < size2; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}
