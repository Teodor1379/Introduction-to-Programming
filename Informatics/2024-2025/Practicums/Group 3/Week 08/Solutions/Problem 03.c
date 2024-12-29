#include <assert.h>

#include <stdio.h>



#define MAX_ROWS 100
#define MAX_COLS 100



void clearStandardInput();



int             readElem(                                   );
unsigned int    readSize(unsigned int MAX, const char* name );



void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);



void printDiagonal1(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);
void printDiagonal2(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);



int main() {
    int matrix[MAX_ROWS][MAX_COLS] = { { 0 } };

    unsigned int rows = readSize(MAX_ROWS, "ROWS");
    unsigned int cols = readSize(MAX_COLS, "COLS");

    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    printDiagonal1(matrix, rows, cols);
    printDiagonal2(matrix, rows, cols);

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
    assert(rows == cols                 );

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
    assert(rows == cols                 );

    printf("The elements of the matrix are:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}


void printDiagonal1(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);
    assert(rows == cols                 );

    printf("The elements of the diagonal 1 are: ");

    for (unsigned int i = 0; i < rows; ++i) {
        printf("%d ", matrix[i][i]);
    }

    putchar('\n');
}

void printDiagonal2(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);
    assert(rows == cols                 );

    printf("The elements of the diagonal 2 are: ");

    for (unsigned int i = 0; i < cols; ++i) {
        printf("%d ", matrix[i][cols - i - 1]);
    }

    putchar('\n');
}
