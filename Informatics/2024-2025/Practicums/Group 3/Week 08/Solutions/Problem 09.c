#include <assert.h>

#include <stdio.h>



#define MAX_ROWS 100
#define MAX_COLS 100



void clearStandardInput();



int             readElem(                                   );
unsigned int    readSize(unsigned int MAX, const char* name );



void inputMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);



int findSumRow(int matrox[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols, unsigned int row);
int findSumCol(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols, unsigned int col);



int findMinRow(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);
int findMaxRow(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);
int findMinCol(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);
int findMaxCol(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);



int main() {
    int matrix[MAX_ROWS][MAX_COLS] = { { 0 } };

    unsigned int rows = readSize(MAX_ROWS, "ROWS");
    unsigned int cols = readSize(MAX_COLS, "COLS");

    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);


    printf("The MIN ROW sum is: %d\n",  findMinRow(matrix, rows, cols));
    printf("The MAX ROW sum is: %d\n",  findMaxRow(matrix, rows, cols));
    printf("The MIN COL sum is: %d\n",  findMinCol(matrix, rows, cols));
    printf("The MAX COL sum is: %d\n",  findMaxCol(matrix, rows, cols));

    
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



int findSumRow(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols, unsigned int row) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);
    assert(row < MAX_ROWS               );

    int sum = 0;

    for (unsigned int i = 0; i < cols; ++i) {
        sum = sum + matrix[row][i];
    }

    return sum;
}

int findSumCol(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols, unsigned int col) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);
    assert(col < MAX_COLS               );

    int sum = 0;

    for (unsigned int i = 0; i < rows; ++i) {
        sum = sum + matrix[i][col];
    }

    return sum;
}



int findMinRow(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);

    int result = findSumRow(matrix, rows, cols, 0);

    for (unsigned int i = 1; i < rows; ++i) {
        int current = findSumRow(matrix, rows, cols, i);

        if (result > current) {
            result = current;
        }
    }

    return result;
}

int findMaxRow(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);
    
    int result = findSumRow(matrix, rows, cols, 0);

    for (unsigned int i = 1; i < rows; ++i) {
        int current = findSumRow(matrix, rows, cols, i);

        if (result < current) {
            result = current;
        }
    }

    return result;
}

int findMinCol(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);

    int result = findSumCol(matrix, rows, cols, 0);

    for (unsigned int i = 1; i < cols; ++i) {
        int current = findSumCol(matrix, rows, cols, i);

        if (result > current) {
            result = current;
        }
    }

    return result;
}

int findMaxCol(int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);
    
    int result = findSumCol(matrix, rows, cols, 0);

    for (unsigned int i = 1; i < cols; ++i) {
        int current = findSumCol(matrix, rows, cols, i);

        if (result < current) {
            result = current;
        }
    }

    return result;
}
