#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>


#define MAX_ROWS 100
#define MAX_COLS 100


void manageInput();


size_t inputSize(size_t MAX, int counter, char name[]);

void inputMatrix(int matrix[][MAX_COLS], size_t rows, size_t cols);
void printMatrix(int matrix[][MAX_COLS], size_t rows, size_t cols);


void matrixAddition     (int matrix1[][MAX_COLS], int matrix2[][MAX_COLS], int result[][MAX_COLS], size_t rows1, size_t cols1, size_t rows2, size_t cols2);
void matrixSubtraction  (int matrix1[][MAX_COLS], int matrix2[][MAX_COLS], int result[][MAX_COLS], size_t rows1, size_t cols1, size_t rows2, size_t cols2);

void matrixMultiplyNum  (int matrix[][MAX_COLS], size_t rows, size_t cols, int number);


int main() {
    size_t rows1 = inputSize(MAX_ROWS, 1, "ROWS");
    size_t cols1 = inputSize(MAX_COLS, 1, "COLS");
    size_t rows2 = inputSize(MAX_ROWS, 2, "ROWS");
    size_t cols2 = inputSize(MAX_COLS, 2, "COLS");

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


void manageInput() {
    while (1) {
        int c = getchar();

        if (c == '\n' || c == EOF) {
            break;
        }
    }
}


size_t inputSize(size_t MAX, int counter, char name[]) {
    size_t size = 0;

    do {
        printf("Enter the %s size of matrix %d: ", name, counter);

        if (scanf("%zu", &size) != 1) {
            printf("Standard Input Error!\n");

            exit(EXIT_FAILURE);
        }

        manageInput();
    } while (size == 0 || size > MAX);

    return size;
}

void inputMatrix(int matrix[][MAX_COLS], size_t rows, size_t cols) {
    if (rows == 0 || rows > MAX_ROWS || cols == 0 || cols > MAX_COLS) {
        printf("Invalid sizes for the matrix!\n");

        exit(EXIT_FAILURE);
    }

    printf("Enter the elements of the matrix:\n");

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Standard Input Error!\n");

                exit(EXIT_FAILURE);
            }
        }
    }
}

void printMatrix(int matrix[][MAX_COLS], size_t rows, size_t cols) {
    if (rows == 0 || rows > MAX_ROWS || cols == 0 || cols > MAX_COLS) {
        printf("Invalid sizes for the matrix!\n");

        exit(EXIT_FAILURE);
    }

    printf("The elements of the matrix are:\n");

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}


void matrixAddition(int matrix1[][MAX_COLS], int matrix2[][MAX_COLS], int matrix[][MAX_COLS], size_t rows1, size_t cols1, size_t rows2, size_t cols2) {
    if (rows1 == 0 || rows1 > MAX_ROWS || cols1 == 0 || cols1 > MAX_COLS || rows1 != rows2 || cols1 != cols2) {
        printf("Invalid sizes for the matrices!\n");

        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < rows1; ++i) {
        for (size_t j = 0; j < cols1; ++j) {
            matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixSubtraction(int matrix1[][MAX_COLS], int matrix2[][MAX_COLS], int matrix[][MAX_COLS], size_t rows1, size_t cols1, size_t rows2, size_t cols2) {
    if (rows1 == 0 || rows1 > MAX_ROWS || cols1 == 0 || cols1 > MAX_COLS || rows1 != rows2 || cols1 != cols2) {
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
    if (rows == 0 || rows > MAX_ROWS || cols == 0 || cols > MAX_COLS) {
        printf("Invalid sizes for the matrix!\n");

        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            matrix[i][j] = matrix[i][j] * number;
        }
    }
} 
