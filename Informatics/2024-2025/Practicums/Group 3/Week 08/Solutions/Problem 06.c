#include <assert.h>

#include <math.h>

#include <stdio.h>



#define EPSILON 1e-9
#define MAX_ROWS 100
#define MAX_COLS 100



void clearStandardInput();



int             readElem(                                   );
unsigned int    readSize(unsigned int MAX, const char* name );



void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);



int areColsLinearDependent(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols, unsigned int col1, unsigned int col2);

int isLinearDependent(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);



int main() {
    int matrix[MAX_ROWS][MAX_COLS] = { { 0 } };

    unsigned int rows = readSize(MAX_ROWS, "ROWS");
    unsigned int cols = readSize(MAX_COLS, "COLS");

    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    int result = isLinearDependent(matrix, rows, cols);

    printf("Has linear dependent cols: %s\n", result ? "Yes" : "No");

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



int areColsLinearDependent(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols, unsigned int col1, unsigned int col2) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);
    assert(col1 < MAX_COLS              );
    assert(col2 < MAX_COLS              );

    double currentCoefficient = (fabs((double)(matrix[0][col2])) < EPSILON) ? 0 : (double)(matrix[0][col1]) / (double)(matrix[0][col2]);

    for (unsigned int k = 1; k < rows; ++k) {
        double coefficient = (fabs((double)(matrix[k][col2])) < EPSILON) ? 0 : (double)(matrix[k][col1]) / (double)(matrix[k][col2]);

        if (fabs(currentCoefficient - coefficient) >= EPSILON) {
            return 0;
        }
    }

    return 1;
}

int isLinearDependent(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);

    for (unsigned int i = 0; i < cols - 1; ++i) {
        for (unsigned int j = i + 1; j < cols; ++j) {
            if (areColsLinearDependent(matrix, rows, cols, i, j)) {
                return 1;
            }
        }
    }

    return 0;
}
