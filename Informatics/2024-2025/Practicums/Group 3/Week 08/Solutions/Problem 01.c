#include <stdlib.h>

#include <stdio.h>



#define MAX_ROWS 100
#define MAX_COLS 100



unsigned int    inputSize   (unsigned int MAX, int counter, char name[] );
int             validateSize(unsigned int MAX, unsigned int size        );


void inputMatrix(int matrix[][MAX_COLS], size_t rows, size_t cols);
void printMatrix(int matrix[][MAX_COLS], size_t rows, size_t cols);


void matrixAddition     (int matrix1[][MAX_COLS], int matrix2[][MAX_COLS], int result[][MAX_COLS], size_t rows1, size_t cols1, size_t rows2, size_t cols2);
void matrixSubtraction  (int matrix1[][MAX_COLS], int matrix2[][MAX_COLS], int result[][MAX_COLS], size_t rows1, size_t cols1, size_t rows2, size_t cols2);

void matrixMultiplyNum  (int matrix[][MAX_COLS], size_t rows, size_t cols, int number);


int main() {
    unsigned int rows1 = inputSize(MAX_ROWS, 1, "ROWS");
    unsigned int cols1 = inputSize(MAX_COLS, 1, "COLS");
    unsigned int rows2 = inputSize(MAX_ROWS, 2, "ROWS");
    unsigned int cols2 = inputSize(MAX_COLS, 2, "COLS");

    putchar('\n');
    putchar('\n');
    putchar('\n');

    int matrix1[MAX_ROWS][MAX_COLS] = { { 0 } };
    int matrix2[MAX_ROWS][MAX_COLS] = { { 0 } };

    inputMatrix(matrix1, rows1, cols1); printMatrix(matrix1, rows1, cols1);
    inputMatrix(matrix2, rows2, cols2); printMatrix(matrix2, rows2, cols2);

    putchar('\n');
    putchar('\n');
    putchar('\n');

    int resultMatrix1[MAX_ROWS][MAX_COLS] = { { 0 } };
    int resultMatrix2[MAX_ROWS][MAX_COLS] = { { 0 } };

    matrixAddition      (matrix1, matrix2, resultMatrix1, rows1, cols1, rows2, cols2);
    matrixSubtraction   (matrix1, matrix2, resultMatrix2, rows1, cols1, rows2, cols2);

    printMatrix(resultMatrix1, rows1, cols1);
    printMatrix(resultMatrix2, rows2, cols2);

    putchar('\n');
    putchar('\n');
    putchar('\n');

    int number = 0;

    printf("Enter the number X: ");

    scanf("%d", &number);

    matrixMultiplyNum(matrix1, rows1, cols1, number);
    matrixMultiplyNum(matrix2, rows1, cols1, number);

    printMatrix(matrix1, rows1, cols1);
    printMatrix(matrix2, rows2, cols2);

    return 0;
}


unsigned int inputSize(unsigned int MAX, int counter, char name[]) {
    unsigned int size = 0;

    do {
        printf("Enter the %s size of matrix %d: ", name, counter);

        if (scanf("%u", &size) != 1) {
            printf("Standard Input Error!\n");

            exit(EXIT_FAILURE);
        }
    } while (size == 0 || size > MAX);

    return size;
}

int validateSize(unsigned int MAX, unsigned int size) {
    return  size != 0 && size <= MAX;
}


void inputMatrix(int matrix[][MAX_COLS], unsigned int rows, unsigned int cols) {
    if (!validateSizes(MAX_ROWS, rows) || !validateSizes(MAX_COLS, cols)) {
        printf("Invalid sizes for the matrix!\n");

        exit(EXIT_FAILURE);
    }

    printf("Enter the elements of the matrix:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            scanf("%d", &(matrix[i][j]));
        }
    }
}

void printMatrix(int matrix[][MAX_COLS], unsigned int rows, unsigned int cols) {
    if (!validateSizes(MAX_ROWS, rows) || !validateSizes(MAX_COLS, cols)) {
        printf("Invalid sizes for the matrix!\n");

        exit(EXIT_FAILURE);
    }

    printf("The elements of the matrix are:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}


void matrixAddition(int matrix1[][MAX_COLS], int matrix2[][MAX_COLS], int matrix[][MAX_COLS], unsigned int rows1, unsigned int cols1, unsigned int rows2, unsigned int cols2) {
    if (
        !validateSizes(MAX_ROWS, rows1) || !validateSizes(MAX_COLS, cols1)  ||
        !validateSizes(MAX_ROWS, rows2) || !validateSizes(MAX_COLS, cols2)  ||
        rows1 != rows2 || cols1 != cols2
    ) {
        printf("Invalid sizes for the matrices!\n");

        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < rows1; ++i) {
        for (unsigned int j = 0; j < cols1; ++j) {
            matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixSubtraction(int matrix1[][MAX_COLS], int matrix2[][MAX_COLS], int matrix[][MAX_COLS], size_t rows1, size_t cols1, size_t rows2, size_t cols2) {
    if (
        !validateSizes(MAX_ROWS, rows1) || !validateSizes(MAX_COLS, cols1)  ||
        !validateSizes(MAX_ROWS, rows2) || !validateSizes(MAX_COLS, cols2)  ||
        rows1 != rows2 || cols1 != cols2
    ) {
        printf("Invalid sizes for the matrices!\n");

        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < rows2; ++i) {
        for (size_t j = 0; j < cols2; ++j) {
            matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrixMultiplyNum(int matrix[][MAX_COLS], size_t rows, size_t cols, int number) {
    if (!validateSizes(MAX_ROWS, rows) || !validateSizes(MAX_COLS, cols)) {
        printf("Invalid sizes for the matrix!\n");

        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            matrix[i][j] = matrix[i][j] * number;
        }
    }
} 
