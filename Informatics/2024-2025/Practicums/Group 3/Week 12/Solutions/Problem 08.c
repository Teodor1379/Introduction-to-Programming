#include <assert.h>

#include <stdlib.h>

#include <stdio.h>



void clearStandardInput();



unsigned int readSize();



unsigned int**  buildMatrix(                            unsigned int rows, unsigned int cols);
void            clearMatrix(unsigned int***  matrix,    unsigned int rows                   );



void printMatrix(const unsigned int* const* matrix, unsigned int rows, unsigned int cols);



void traverseMatrix(unsigned int** matrix, unsigned int rows, unsigned int cols);



unsigned int factorial  (                   unsigned int n);
unsigned int binomial   (unsigned int k,    unsigned int n);



int main() {
    unsigned int rows   =   readSize();
    unsigned int cols   =   readSize();


    unsigned int** matrix = buildMatrix(rows, cols);


    if (matrix == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    traverseMatrix(matrix, rows, cols);

    printMatrix((const unsigned int* const*)matrix, rows, cols);


    unsigned int result1 = binomial(rows - 1, rows + cols - 2)  ;   //  Overflow
    unsigned int result2 = binomial(cols - 1, rows + cols - 2)  ;   //  Overflow
    unsigned int result3 = matrix[0][cols - 1]                  ;   //  Correct

    printf("The result 1 is: %u\n", result1);
    printf("The result 2 is: %u\n", result2);
    printf("The result 3 is: %u\n", result3);


    clearMatrix(&matrix, rows);


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readSize() {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the size of the rectangle: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0);

    return size;
}



unsigned int** buildMatrix(unsigned int rows, unsigned int cols) {
    assert(rows !=  0);
    assert(cols !=  0);

    unsigned int** result = (unsigned int**)(malloc(rows * sizeof(unsigned int*)));

    if (result != NULL) {
        for (unsigned int i = 0; i < rows; ++i) {
            result[i] = (unsigned int*)(malloc(cols * sizeof(int)));

            if (result[i] == NULL) {
                clearMatrix(&result, i);

                return NULL;
            }

            for (unsigned int j = 0; j < cols; ++j) {
                result[i][j] = 0;
            }
        }
    }

    return result;
}

void clearMatrix(unsigned int*** matrix, unsigned int rows) {
    assert(*matrix  !=  NULL);
    assert(rows     !=  0   );

    for (unsigned int i = 0; i < rows; ++i) {
        free((*matrix)[i]);
    }

    free(*matrix);

    *matrix = NULL;
}



void printMatrix(const unsigned int* const* matrix, unsigned int rows, unsigned int cols) {
    assert(matrix   !=  NULL);
    assert(rows     !=  0   );
    assert(cols     !=  0   );

    printf("The matrix is:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}



void traverseMatrix(unsigned int** matrix, unsigned int rows, unsigned int cols) {
    assert(matrix   !=  NULL);
    assert(rows     !=  0   );
    assert(cols     !=  0   );

    for (unsigned int i = 0; i < rows; ++i) {
        matrix[i][0] = 1;
    }

    for (unsigned int i = 0; i < cols; ++i) {
        matrix[rows - 1][i] = 1;
    }

    for (unsigned int i = rows - 2; i >= 0; --i) {
        for (unsigned int j = 1; j < cols; ++j) {
            matrix[i][j] = matrix[i + 1][j] + matrix[i][j - 1];
        }

        if (i == 0) {
            break;
        }
    }
}



unsigned int factorial(unsigned int n) {
    if (n == 0) {
        return 1;
    }

    return n * factorial(n - 1);
}

unsigned int binomial(unsigned int k, unsigned int n) {
    assert(k <= n);

    unsigned int numerator      =   factorial(n)                    ;
    unsigned int denominator    =   factorial(k) * factorial(n - k) ;

    return numerator / denominator;
}
