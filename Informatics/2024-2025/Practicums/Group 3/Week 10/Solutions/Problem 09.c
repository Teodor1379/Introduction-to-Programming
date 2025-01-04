#include <assert.h>

#include <limits.h>

#include <stdlib.h>

#include <stdio.h> 



void clearStandardInput();



unsigned int    readElem(                   );
unsigned int    readIndx(unsigned int size  );
unsigned int    readSize(const char* name   );



int**   buildMatrix(                            unsigned int rows, unsigned int cols);
void    clearMatrix(           int***   matrix, unsigned int rows                   );

void    inputMatrix(            int**   matrix, unsigned int rows, unsigned int cols);
void    printMatrix(const int* const*   matrix, unsigned int rows, unsigned int cols);



void deleteRowMatrix(int*** matrix, unsigned int* rows, unsigned int index);



int main() {
    unsigned int rows   =   readSize("ROWS");
    unsigned int cols   =   readSize("COLS");


    int** matrix = buildMatrix(rows, cols);

    if (matrix == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }

    
    const int* const* pointr = (const int* const*)(matrix);

    inputMatrix(matrix, rows, cols);
    printMatrix(pointr, rows, cols);


    unsigned int index = readIndx(rows);

    deleteRowMatrix(&matrix, &rows, index);

    printMatrix(pointr, rows, cols);


    clearMatrix(&matrix, rows);


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readElem() {
    unsigned int elem   =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%u", &elem);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return elem;
}

unsigned int readIndx(unsigned int size) {
    unsigned int indx   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the indx: ");

        inputArgument = scanf("%u", &indx);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || indx >= size);

    return indx;
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
                clearMatrix(&matrix, i);

                return NULL;
            }
        }
    }

    return matrix;
}

void clearMatrix(int*** matrix, unsigned int rows) {
    assert(*matrix != NULL);

    for (unsigned int i = 0; i < rows; ++i) {
        free((*matrix)[i]);
    }

    free(*matrix);

    *matrix = NULL;
}



void inputMatrix(int** matrix, unsigned int rows, unsigned int cols) {
    assert(matrix != NULL);

    assert(rows != 0);
    assert(cols != 0);

    printf("Enter the elements of the matrix:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            matrix[i][j] = readElem();
        }
    }
}

void printMatrix(const int* const* matrix, unsigned int rows, unsigned int cols) {
    assert(matrix != NULL);

    assert(cols != 0);

    if (rows == 0) {
        printf("The matrix is empty!\n");

        return;
    }

    printf("The elements of the matrix are:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}



void deleteRowMatrix(int*** matrix, unsigned int* rows, unsigned int index) {
    assert(*matrix  != NULL );
    assert(rows     != NULL );
    assert(*rows    != 0    );
    assert(index    < *rows );

    if (index == *rows - 1) {
        free((*matrix)[index]);

        *rows = *rows - 1;
    } else {
        free((*matrix)[index]);

        for (unsigned int i = index; i < *rows - 1; ++i) {
            (*matrix)[i] = (*matrix)[i + 1];
        }

        *rows = *rows - 1;
    }
}
