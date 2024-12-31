#include <assert.h>

#include <limits.h>

#include <stdlib.h>

#include <stdio.h>



void clearStandardInput();



int             readElem();
unsigned int    readSize();



int**   buildMatrix(                            unsigned int rows   );
void    clearMatrix(            int**   matrix, unsigned int rows   );

void    printMatrix(const int* const*   matrix, unsigned int rows   );



int main() {
    unsigned int rows   =   readSize();


    int** matrix = buildMatrix(rows);

    if (matrix == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    const int* const* pointr = (const int* const*)(matrix);

    printMatrix(pointr, rows);


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

unsigned int readSize() {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the size of the matrix: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > UINT_MAX);

    return size;
}



int** buildMatrix(unsigned int rows) {
    assert(rows != 0);

    int** matrix = (int**)(malloc(rows * sizeof(int*)));

    if (matrix != NULL) {
        for (unsigned int i = 0; i < rows; ++i) {
            matrix[i] = (int*)(malloc((i + 1) * sizeof(int)));

            if (matrix[i] == NULL) {
                clearMatrix(matrix, rows);

                return NULL;
            }

            for (unsigned int j = 0; j < i + 1; ++j) {
                matrix[i][j] = j + 1;
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


void printMatrix(const int* const* matrix, unsigned int rows) {
    assert(matrix   != NULL );
    assert(rows     != 0    );

    printf("The elements of the matrix are:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < i + 1; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}
