#include <assert.h>

#include <stdio.h>


#define MAX_SIZE 100


void clearStandardInput();



unsigned int    readElem();
unsigned int    readSize();



void inputMatrix(unsigned int matrix[MAX_SIZE][MAX_SIZE], unsigned int size);
void printMatrix(unsigned int matrix[MAX_SIZE][MAX_SIZE], unsigned int size);



unsigned int sumDiagonalsMatrix(unsigned int matrix[MAX_SIZE][MAX_SIZE], unsigned int size);



int main() {
    unsigned int matrix[MAX_SIZE][MAX_SIZE] = { { 0 } };

    unsigned int size = readSize();

    inputMatrix(matrix, size);
    printMatrix(matrix, size);

    unsigned int sum = sumDiagonalsMatrix(matrix, size);

    printf("The sum of the elements on the diagonals is: %d\n", sum);

    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readElem() {
    unsigned int elem   =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%u", &elem);

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
        printf("Enter the size of the matrix: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return size;
}



void inputMatrix(unsigned int matrix[MAX_SIZE][MAX_SIZE], unsigned int size) {
    assert(size != 0 && size <= MAX_SIZE);

    printf("Enter the matrix:\n");

    for (unsigned int i = 0; i < size; ++i) {
        for (unsigned int j = 0; j < size; ++j) {
            matrix[i][j] = readElem();
        }
    }
}

void printMatrix(unsigned int matrix[MAX_SIZE][MAX_SIZE], unsigned int size) {
    assert(size != 0 && size <= MAX_SIZE);

    printf("The matrix is:\n");

    for (unsigned int i = 0; i < size; ++i) {
        for (unsigned int j = 0; j < size; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}



unsigned int sumDiagonalsMatrix(unsigned int matrix[MAX_SIZE][MAX_SIZE], unsigned int size) {
    assert(size != 0 && size <= MAX_SIZE);

    unsigned int sum = 0;

    for (unsigned int i = 0; i < size; ++i) {
        sum = sum + matrix[i][i]            ;
        sum = sum + matrix[i][size - i - 1] ;

        if (i == size - i - 1) {
            sum = sum - matrix[i][i];
        }
    }

    return sum;
}

