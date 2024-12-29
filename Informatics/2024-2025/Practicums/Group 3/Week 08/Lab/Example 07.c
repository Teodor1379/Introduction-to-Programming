#include <assert.h>

#include <stdio.h>



#define MAX_SIZE1 100
#define MAX_SIZE2 100



void clearStandardInput();



int             readElem(                                   );
unsigned int    readSize(unsigned int MAX, const char* name );



void inputMatrix(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2);
void printMatrix(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2);



void printDiagonal1(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2);
void printDiagonal2(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2);



int sumAboveDiagonal1(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2);
int sumAboveDiagonal2(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2);
int sumBelowDiagonal1(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2);
int sumBelowDiagonal2(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2);



int main() {
    int matrix[MAX_SIZE1][MAX_SIZE2] = { { 0 } };

    unsigned int size1 = readSize(MAX_SIZE1, "ROWS");
    unsigned int size2 = readSize(MAX_SIZE2, "COLS");

    inputMatrix(matrix, size1, size2);
    printMatrix(matrix, size1, size2);

    printDiagonal1(matrix, size1, size2);
    printDiagonal2(matrix, size1, size2);

    printf("The sum above Diagonal 1 is: %d\n", sumAboveDiagonal1(matrix, size1, size2));
    printf("The sum below Diagonal 1 is: %d\n", sumBelowDiagonal1(matrix, size1, size2));
    printf("The sum above Diagonal 2 is: %d\n", sumAboveDiagonal2(matrix, size1, size2));
    printf("The sum below Diagonal 2 is: %d\n", sumBelowDiagonal2(matrix, size1, size2));

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




void inputMatrix(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2) {
    assert(size1 != 0 && size1 <= MAX_SIZE1 );
    assert(size2 != 0 && size2 <= MAX_SIZE2 );

    printf("Enter the elements of the matrix:\n");

    for (unsigned int i = 0; i < size1; ++i) {
        for (unsigned int j = 0; j < size2; ++j) {
            matrix[i][j] = readElem();
        }
    }
}

void printMatrix(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2) {
    assert(size1 != 0 && size1 <= MAX_SIZE1 );
    assert(size2 != 0 && size2 <= MAX_SIZE2 );

    printf("The elements of the matrix are:\n");

    for (unsigned int i = 0; i < size1; ++i) {
        for (unsigned int j = 0; j < size2; ++j) {
            printf("%d ", matrix[i][j]);
        }

        putchar('\n');
    }
}



void printDiagonal1(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2) {
    assert(size1 != 0 && size1 <= MAX_SIZE1 );
    assert(size2 != 0 && size2 <= MAX_SIZE2 );

    unsigned int size = (size1 < size2) ? size1 : size2;

    // 0 <= Index < Size1 (Index of Row)
    // 0 <= Index < Size2 (Index of Col)
    // => Index < min { Size1, Size2 }

    printf("Diagonal 1 is: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", matrix[i][i]);
    }

    putchar('\n');
}

void printDiagonal2(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2) {
    assert(size1 != 0 && size1 <= MAX_SIZE1 );
    assert(size2 != 0 && size2 <= MAX_SIZE2 );
    
    unsigned int size = (size1 < size2) ? size1 : size2;

    // Index < Size1 (Because Index is of Row)
    // Index < Size2 (Because ...)
    //      Index <= Size2 - 1 (Because ...)
    //          0 <= Size2 - Index - 1
    
    // 0 <= Index < Size1 (Index of Row)
    // 0 <= Index < Size2 (Index of Col)
    // => Index < min { Size1, Size2 }

    printf("Diagonal 2 is: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", matrix[i][size2 - i - 1]);
    }

    putchar('\n');
}



int sumAboveDiagonal1(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2) {
    assert(size1 != 0 && size1 <= MAX_SIZE1 );
    assert(size2 != 0 && size2 <= MAX_SIZE2 );

    int sum = 0;

    unsigned int size = (size1 < size2 - 1) ? size1 : (size2 - 1);

    for (unsigned int i = 0; i < size; ++i) {
        for (unsigned int j = i + 1; j < size2; ++j) {
            sum = sum + matrix[i][j];
        }
    }

    return sum;
}

int sumAboveDiagonal2(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2) {
    assert(size1 != 0 && size1 <= MAX_SIZE1 );
    assert(size2 != 0 && size2 <= MAX_SIZE2 );

    int sum = 0;

    unsigned int size = (size1 < size2) ? size1 : size2;

    for (unsigned int i = 0; i < size; ++i) {
        for (unsigned int j = 0; j < size2 - i - 1; ++j) {
            sum = sum + matrix[i][j];
        }
    }

    return sum;
}

int sumBelowDiagonal1(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2) {
    assert(size1 != 0 && size1 <= MAX_SIZE1 );
    assert(size2 != 0 && size2 <= MAX_SIZE2 );

    int sum = 0;

    for (unsigned int i = 1; i < size1; ++i) {
        unsigned int min = (size2 < i) ? size2 : i;

        for (unsigned int j = 0; j < min; ++j) {
            sum = sum + matrix[i][j];
        }
    }

    return sum;
}

int sumBelowDiagonal2(int matrix[MAX_SIZE1][MAX_SIZE2], unsigned int size1, unsigned int size2) {
    assert(size1 != 0 && size1 <= MAX_SIZE1 );
    assert(size2 != 0 && size2 <= MAX_SIZE2 );

    int sum = 0;

    for (unsigned int i = 1; i < size1; ++i) {
        unsigned int size = (i < size2 ? size2 - i : 0);

        for (unsigned int j = size; j < size2; ++j) {
            sum = sum + matrix[i][j];
        }
    }

    return sum;
}
