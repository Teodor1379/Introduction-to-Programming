#include <assert.h>

#include <stdio.h>



#define MAX_ROWS 100
#define MAX_COLS 100



void clearStandardInput();



int             readElem(                                   );
unsigned int    readSize(unsigned int MAX, const char* name );



void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);



void traverseMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);



int main() {
    int matrix[MAX_ROWS][MAX_COLS] = { { 0 } };

    unsigned int rows   =   readSize(MAX_ROWS, "ROWS");
    unsigned int cols   =   readSize(MAX_COLS, "COLS");

    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    traverseMatrix(matrix, rows, cols);

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
        printf("Enter the %s of the matrix: ", name);

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX);

    return size;
}



void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);

    printf("Enter the elements of the matrix:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            matrix[i][j] = readElem();
        }
    }
}

void printMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);

    printf("The elements of the matrix are:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}



void traverseMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);

    long long   cornerRows1 =   0       ;
    long long   cornerRows2 =   rows - 1;

    long long   cornerCols1 =   0       ;
    long long   cornerCols2 =   cols - 1;

    unsigned int counter    =   0       ;

    putchar('\n');

    printf("The traverse of the matrix is: ");

    while (counter < rows * cols) {
        for (long long i = cornerCols1; i <= cornerCols2; ++i) {
            printf("%d ", matrix[cornerRows1][i]);

            counter = counter + 1;
        }

        cornerRows1 = cornerRows1 + 1;

        for (long long i = cornerRows1; i <= cornerRows2; ++i) {
            printf("%d ", matrix[i][cornerCols2]);

            counter = counter + 1;
        }

        cornerCols2 = cornerCols2 - 1;

        for (long long i = cornerCols2; i >= cornerCols1; --i) {
            printf("%d ", matrix[cornerRows2][i]);

            counter = counter + 1;
        }

        cornerRows2 = cornerRows2 - 1;

        for (long long i = cornerRows2; i >= cornerRows1; --i) {
            printf("%d ", matrix[i][cornerCols1]);

            counter = counter + 1;
        }

        cornerCols1 = cornerCols1 + 1;
    }

    putchar('\n');
}
