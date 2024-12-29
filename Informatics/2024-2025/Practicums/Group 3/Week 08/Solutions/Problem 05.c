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



int areRowsLinearDependent(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols, unsigned int row1, unsigned int row2);

int isLinearDependent(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);




int main() {
    int matrix[MAX_ROWS][MAX_COLS] = { { 0 } };

    unsigned int rows = readSize(MAX_ROWS, "ROWS");
    unsigned int cols = readSize(MAX_COLS, "COLS");

    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    int result = isLinearDependent(matrix, rows, cols);

    printf("Has linear dependent rows: %s\n", result ? "Yes" : "No");

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

unsigned int readSize(unsigned int MAX_SIZE, const char* name) {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the %s size of the matrix: ", name);

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX_SIZE);

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



int areRowsLinearDependent(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols, unsigned int row1, unsigned int row2) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);
    assert(row1 < MAX_ROWS              );
    assert(row2 < MAX_ROWS              );

    double currentCoefficient = (fabs((double)(matrix[row2][0])) < EPSILON) ? 0 : (double)(matrix[row1][0]) / (double)(matrix[row2])[0];

    for (unsigned int k = 1; k < cols; ++k) {
        double coefficient = (fabs((double)(matrix[row2][k])) < EPSILON) ? 0 : (double)(matrix[row1][k]) / (double)(matrix[row2][k]);

        if (fabs(currentCoefficient - coefficient) >= EPSILON) {
            return 0;
        }
    }

    return 1;
}

int isLinearDependent(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);

    for (unsigned int i = 0; i < rows - 1; ++i) {
        for (unsigned int j = i + 1; j < rows; ++j) {
            if (areRowsLinearDependent(matrix, rows, cols, i, j)) {
                return 1;
            }
        }
    }

    return 0;
}
