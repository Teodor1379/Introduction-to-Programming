#include <assert.h>

#include <stdlib.h>

#include <stdio.h>



void clearStandardInput();



unsigned int readNumb(                  );
unsigned int readSize(const char* string);



int** buildMatrix(                          unsigned int rows, unsigned int cols);
int** duplcMatrix(const int* const* matrix, unsigned int rows, unsigned int cols);
void  clearMatrix(           int*** matrix, unsigned int rows                   );



void inputMatrix(int** matrix, unsigned int rows, unsigned int cols);
void printMatrix(int** matrix, unsigned int rows, unsigned int cols);



void traverseMatrix(int** matrix, unsigned int rows, unsigned int cols, unsigned int index1, unsigned int index2);



unsigned int findFields(int** matrix, unsigned int rows, unsigned int cols);



int main() {
    unsigned int size1  =   readSize("ROWS");
    unsigned int size2  =   readSize("COLS");


    int** matrix = buildMatrix(size1, size2);

    if (matrix == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    } else {
        inputMatrix(matrix, size1, size2);
        printMatrix(matrix, size1, size2);
    }

    int** duplicate = duplcMatrix((const int* const*)(matrix), size1, size2);

    if (duplicate == NULL) {
        puts("Allocating Memory... ERROR!");

        clearMatrix(&matrix, size1);

        return 1;
    }


    unsigned int fields = findFields(duplicate, size1, size2);

    printf("The number of fields in the matrix are: %u\n",  fields);


    clearMatrix(&matrix,    size1);
    clearMatrix(&duplicate, size1);


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readNumb() {
    unsigned int numb   =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%u", &numb);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || numb > 2);

    return numb;
}

unsigned int readSize(const char* string) {
    assert(string   !=  NULL);

    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the %s size of the matrix: ", string);

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        } 
    } while (inputArgument != 1 || size == 0);

    return size;
}



int** buildMatrix(unsigned int rows, unsigned int cols) {
    assert(rows     !=  0   );
    assert(cols     !=  0   );

    int** matrix = (int**)(malloc(rows * sizeof(int*)));

    for (unsigned int i= 0; i < rows; ++i) {
        matrix[i] = (int*)(malloc(cols * sizeof(int)));

        if (matrix[i] == NULL) {
            clearMatrix(&matrix, i);

            return NULL;
        }
    }

    return matrix;
}

int** duplcMatrix(const int* const* matrix, unsigned int rows, unsigned int cols) {
    assert(matrix   !=  NULL);
    assert(rows     !=  0   );
    assert(cols     !=  0   );

    int** result = (int**)(malloc(rows * sizeof(int*)));

    if (result != NULL) {
        for (unsigned int i = 0; i < rows; ++i) {
            result[i] = malloc(cols * sizeof(int));

            if (result[i] == NULL) {
                clearMatrix(&result, i);

                return NULL;
            }

            for (unsigned int j = 0; j < cols; ++j) {
                result[i][j] = matrix[i][j];
            }
        }
    }

    return result;
}

void clearMatrix(int*** matrix, unsigned int rows) {
    assert(*matrix  !=  NULL);
    assert(rows     !=  0   );
    
    for (unsigned int i = 0; i < rows; ++i) {
        free((*matrix)[i]);
    }

    free(*matrix);

    *matrix = NULL;
}



void inputMatrix(int** matrix, unsigned int rows, unsigned int cols) {
    assert(matrix   !=  NULL);
    assert(rows     !=  0   );
    assert(cols     !=  0   );

    printf("Enter the elements of the matrix:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            matrix[i][j] = readNumb();
        }
    }
}

void printMatrix(int** matrix, unsigned int rows, unsigned int cols) {
    assert(matrix   !=  NULL);
    assert(rows     !=  0   );
    assert(cols     !=  0   );

    printf("The elements of the matrix are:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}



void traverseMatrix(int** matrix, unsigned int rows, unsigned int cols, unsigned int index1, unsigned int index2) {
    assert(matrix   !=  NULL);
    assert(rows     !=  0   );
    assert(cols     !=  0   );

    if (index1 >= rows || index2 >= cols) {
        return;
    }

    if (matrix[index1][index2] == 0) {
        return;
    }

    matrix[index1][index2] = 0;

    traverseMatrix(matrix, rows, cols, index1 + 1, index2);
    traverseMatrix(matrix, rows, cols, index1 - 1, index2);
    traverseMatrix(matrix, rows, cols, index1, index2 + 1);
    traverseMatrix(matrix, rows, cols, index1, index2 - 1);
}



unsigned int findFields(int** matrix, unsigned int rows, unsigned int cols) {
    assert(matrix   !=  NULL);
    assert(rows     !=  0   );
    assert(cols     !=  0   );

    unsigned int fields = 0;

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            if (matrix[i][j]) {
                traverseMatrix(matrix, rows, cols, i, j);

                fields = fields + 1;
            }
        }
    }

    return fields;
}
