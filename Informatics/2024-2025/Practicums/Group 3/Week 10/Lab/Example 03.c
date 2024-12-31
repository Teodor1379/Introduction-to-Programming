#include <assert.h>

#include <limits.h>

#include <stdlib.h>

#include <stdio.h>



void clearStandardInput();



int             readElem(                   );
unsigned int    readSize(const char* name   );



int**   buildMatrix(                unsigned int rows, unsigned int cols);
void    clearMatrix(int** array,    unsigned int rows                   );

void    inputMatrix(                 int**  matrix, unsigned int rows, unsigned int cols);
void    printMatrix(const int* const*       matrix, unsigned int rows, unsigned int cols);



int main() {
    unsigned int rows = readSize("ROWS");
    unsigned int cols = readSize("COLS");

    int** matrix = buildMatrix(rows, cols);

    if (matrix == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }

    const int* const* pointr = (const int* const*)(matrix);

    inputMatrix(matrix, rows, cols);
    printMatrix(pointr, rows, cols);

    clearMatrix(matrix, rows);
    
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

unsigned int readSize(const char* name) {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the %s size of the matrix: ", name);

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > UINT_MAX);

    return size;
}



int** buildMatrix(unsigned int rows, unsigned int cols) {
    assert(rows != 0);
    assert(cols != 0);

    int** matrix = (int**)(malloc(rows * sizeof(int*)));

    if (matrix != NULL) {
        for (unsigned int i = 0; i < rows; ++i) {
            matrix[i] = (int*)(malloc(cols * sizeof(int)));

            if (matrix[i] == NULL) {
                clearMatrix(matrix, i);

                return NULL;
            }
        }
    }

    return matrix;
}

void clearMatrix(int** matrix, unsigned int rows) {
    assert(matrix   != NULL );
    assert(rows     != 0    );

    for (unsigned int i = 0; i < rows; ++i) {
        free(matrix[i]);
    }

    free(matrix);

    matrix = NULL;
}


void inputMatrix(int** matrix, unsigned int rows, unsigned int cols) {
    assert(matrix   != NULL );
    assert(rows     != 0    );
    assert(cols     != 0    );

    printf("Enter the elements of the matrix:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            matrix[i][j] = readElem();
        }
    }
}

void printMatrix(const int* const* matrix, unsigned int rows, unsigned int cols) {
    assert(matrix   != NULL );
    assert(rows     != 0    );
    assert(cols     != 0    );

    printf("The elements of the matrix are:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}
