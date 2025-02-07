#include <assert.h>

#include <math.h>

#include <stdlib.h>

#include <stdio.h>



typedef unsigned long long int  sizeType;



void clearStandardInput();



long long int readCoordinate(const char c, unsigned int number);



sizeType**  buildMatrix(                        sizeType rows, sizeType cols);
void        clearMatrix(sizeType***  matrix,    sizeType rows               );

void        printMatrix(const sizeType* const* matrix, sizeType rows, sizeType cols);



void    traverseMatrix(sizeType** matrix, sizeType rows, sizeType cols);



int main() {
    long long int   x1  =   readCoordinate('X', 1);
    long long int   y1  =   readCoordinate('Y', 1);
    long long int   x2  =   readCoordinate('X', 2);
    long long int   y2  =   readCoordinate('Y', 2);

    sizeType    rows    =   llabs(x1 - x2);
    sizeType    cols    =   llabs(y1 - y2);



    if (rows == 0 || cols == 0) {
        if (rows == 0 && cols != 0) {
            printf("The number of ways is: 1\n");

            return 1;
        } else if (rows != 0 && cols == 0) {
            printf("The number of ways is: 1\n");

            return 1;
        } else {
            printf("The number of ways is: 0\n");

            return 1;
        }
    }



    sizeType** matrix = buildMatrix(rows, cols);

    if (matrix == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    traverseMatrix(matrix, rows, cols);

    printf("The number of ways is: %llu\n", matrix[rows - 1][cols - 1]);


    clearMatrix(&matrix, rows);



    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



long long int readCoordinate(const char c, unsigned int number) {
    long long int coordinate    =   0;
    int inputArgument           =   0;

    do {
        printf("Enter the coordinate %c%u: ", c, number);

        inputArgument = scanf("%lld", &coordinate);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return coordinate;
}



sizeType** buildMatrix(sizeType rows, sizeType cols) {
    assert(rows !=  0);
    assert(cols !=  0);

    sizeType** matrix = (sizeType**)(malloc(rows * sizeof(sizeType*)));

    for (sizeType i = 0; i < rows; ++i) {
        matrix[i] = (sizeType*)(malloc(cols * sizeof(sizeType)));

        if (matrix[i] == NULL) {
            clearMatrix(&matrix, i);

            return NULL;
        }

        for (sizeType j = 0; j < cols; ++j) {
            matrix[i][j] = 0;
        }
    }

    return matrix;
}

void clearMatrix(sizeType*** matrix, sizeType rows) {
    assert(matrix   !=  NULL);
    assert(rows     !=  0   );

    for (sizeType i = 0; i < rows; ++i) {
        free((*matrix)[i]);
    }

    free(*matrix);

    *matrix = NULL;
}



void printMatrix(const sizeType* const* matrix, sizeType rows, sizeType cols) {
    assert(matrix   !=  NULL);
    assert(rows     !=  0   );
    assert(cols     !=  0   );

    printf("The elements of the matrix are:\n");

    for (sizeType i = 0; i < rows; ++i) {
        for (sizeType j = 0; j < cols; ++j) {
            printf("%llu ", matrix[i][j]);
        }

        putchar('\n');
    }
}



void traverseMatrix(sizeType** matrix, sizeType rows, sizeType cols) {
    assert(matrix   !=  NULL);
    assert(rows     !=  0   );
    assert(cols     !=  0   );

    for (sizeType i = 0; i < rows; ++i) {
        matrix[i][0] = 1;
    }

    for (sizeType i = 0; i < cols; ++i) {
        matrix[0][i] = 1;
    }

    for (sizeType i = 1; i < rows; ++i) {
        for (sizeType j = 1; j < cols; ++j) {
            matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
        }
    }
}
