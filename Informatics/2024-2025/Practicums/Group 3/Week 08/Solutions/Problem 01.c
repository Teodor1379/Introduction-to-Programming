#include <assert.h>

#include <stdio.h>



#define MAX_ROWS 100
#define MAX_COLS 100



void clearStandardInput();



int             readElem    (                                                   );
unsigned int    readSize    (unsigned int MAX, int counter, const char* name    );



void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);



void matrixAddition     (int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], unsigned int rows1, unsigned int cols1, unsigned int rows2, unsigned int cols2);
void matrixSubtraction  (int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int result[MAX_ROWS][MAX_COLS], unsigned int rows1, unsigned int cols1, unsigned int rows2, unsigned int cols2);

void matrixMultiplyNum  (int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols, int number);



int main() {
    int matrix1[MAX_ROWS][MAX_COLS] = { { 0 } };
    int matrix2[MAX_ROWS][MAX_COLS] = { { 0 } };

    unsigned int rows1 = readSize(MAX_ROWS, 1, "ROWS");
    unsigned int cols1 = readSize(MAX_COLS, 1, "COLS");
    unsigned int rows2 = readSize(MAX_ROWS, 2, "ROWS");
    unsigned int cols2 = readSize(MAX_COLS, 2, "COLS");

    putchar('\n');
    putchar('\n');
    putchar('\n');

    inputMatrix(matrix1, rows1, cols1); printMatrix(matrix1, rows1, cols1);
    inputMatrix(matrix2, rows2, cols2); printMatrix(matrix2, rows2, cols2);


    int resultMatrix1[MAX_ROWS][MAX_COLS] = { { 0 } };
    int resultMatrix2[MAX_ROWS][MAX_COLS] = { { 0 } };
    
    putchar('\n');
    putchar('\n');
    putchar('\n');

    matrixAddition      (matrix1, matrix2, resultMatrix1, rows1, cols1, rows2, cols2);
    matrixSubtraction   (matrix1, matrix2, resultMatrix2, rows1, cols1, rows2, cols2);

    printMatrix(resultMatrix1, rows1, cols1);
    printMatrix(resultMatrix2, rows2, cols2);

    putchar('\n');
    putchar('\n');
    putchar('\n');

    printf("Enter the number X: ");

    int number = readElem();

    matrixMultiplyNum(matrix1, rows1, cols1, number);
    matrixMultiplyNum(matrix2, rows1, cols1, number);

    printMatrix(matrix1, rows1, cols1);
    printMatrix(matrix2, rows2, cols2);


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

unsigned int readSize(unsigned int MAX, int counter, const char* name) {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the %s size of matrix %d: ", name, counter);

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX);

    return size;
}



void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS    );
    assert(cols != 0 && cols <= MAX_COLS    );

    printf("Enter the elements of the matrix:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            matrix[i][j] = readElem();
        }
    }
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS    );
    assert(cols != 0 && cols <= MAX_COLS    );

    printf("The elements of the matrix are:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}



void matrixAddition(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int matrix[MAX_ROWS][MAX_COLS], unsigned int rows1, unsigned int cols1, unsigned int rows2, unsigned int cols2) {
    assert(rows1 != 0 && rows1 <= MAX_ROWS  );
    assert(rows2 != 0 && rows2 <= MAX_ROWS  );
    assert(cols1 != 0 && cols1 <= MAX_COLS  );
    assert(cols2 != 0 && cols2 <= MAX_COLS  );
    assert(rows1 == rows2 && cols1 == cols2 );

    for (unsigned int i = 0; i < rows1; ++i) {
        for (unsigned int j = 0; j < cols1; ++j) {
            matrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixSubtraction(int matrix1[MAX_ROWS][MAX_COLS], int matrix2[MAX_ROWS][MAX_COLS], int matrix[MAX_ROWS][MAX_COLS], unsigned int rows1, unsigned int cols1, unsigned int rows2, unsigned int cols2) {
    assert(rows1 != 0 && rows1 <= MAX_ROWS  );
    assert(rows2 != 0 && rows2 <= MAX_ROWS  );
    assert(cols1 != 0 && cols1 <= MAX_COLS  );
    assert(cols2 != 0 && cols2 <= MAX_COLS  );
    assert(rows1 == rows2 && cols1 == cols2 );

    for (unsigned int i = 0; i < rows2; ++i) {
        for (unsigned int j = 0; j < cols2; ++j) {
            matrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void matrixMultiplyNum(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols, int number) {
    assert(rows != 0 && rows <= MAX_ROWS    );
    assert(cols != 0 && cols <= MAX_COLS    );

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            matrix[i][j] = matrix[i][j] * number;
        }
    }
} 
