#include <assert.h>

#include <stdio.h>



#define MAX_ELMS 100

#define MAX_ROWS 100
#define MAX_COLS 100



void clearStandardInput();



unsigned int    readElem();

unsigned int    readSize1(unsigned int MAX);
unsigned int    readSize2(unsigned int MAX, const char* name);



void inputArray(unsigned int array[MAX_ELMS], unsigned int size);
void printArray(unsigned int array[MAX_ELMS], unsigned int size);

void inputMatrix(unsigned int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);
void printMatrix(unsigned int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);



void generatePrefixSumsArray(unsigned int array[MAX_ELMS], unsigned int result[MAX_ELMS], unsigned int size);
void generateSuffixSumsArray(unsigned int array[MAX_ELMS], unsigned int result[MAX_ELMS], unsigned int size);

void generatePrefixSumsMatrix(unsigned int matrix[MAX_ROWS][MAX_COLS], unsigned int result[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);
void generateSuffixSumsMatrix(unsigned int matrix[MAX_ROWS][MAX_COLS], unsigned int result[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols);



void solutionArray  ();
void solutionMatrix ();



int main() {
    solutionArray   ();
    solutionMatrix  ();

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



unsigned int readSize1(unsigned int MAX) {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the size of the array: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX);

    return size;
}

unsigned int readSize2(unsigned int MAX, const char* name) {
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



void inputArray(unsigned int array[MAX_ELMS], unsigned int size) {
    assert(size != 0 && size <= MAX_ELMS);

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(unsigned int array[MAX_ELMS], unsigned int size) {
    assert(size != 0 && size <= MAX_ELMS);

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}


void inputMatrix(unsigned int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    assert(rows != 0 && rows <= MAX_ROWS);
    assert(cols != 0 && cols <= MAX_COLS);

    printf("Enter the elements of the matrix:\n");

    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            matrix[i][j] = readElem();
        }
    }
}

void printMatrix(unsigned int matrix[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
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



void generatePrefixSumsArray(unsigned int array[MAX_ELMS], unsigned int result[MAX_ELMS], unsigned int size) {
    for (unsigned int i = 0; i < size; ++i) {
        if (i == 0) {
            result[i] = array[i];
        } else {
            result[i] = result[i - 1] + array[i];
        }
    }
}

void generateSuffixSumsArray(unsigned int array[MAX_ELMS], unsigned int result[MAX_ELMS], unsigned int size) {
    for (long long i = size - 1; i >= 0; --i) {
        if (i == size - 1) {
            result[i] = array[i];
        } else {
            result[i] = result[i + 1] + array[i];
        }
    }
}


void generatePrefixSumsMatrix(unsigned int matrix[MAX_ROWS][MAX_COLS], unsigned int result[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    for (unsigned int i = 0; i < rows; ++i) {
        for (unsigned int j = 0; j < cols; ++j) {
            if (i == 0 && j == 0) {
                result[i][j] = matrix[i][j];
            } else {
                unsigned int m = (i < j) ? i : j;

                unsigned int sum1   =   ((i > 0) ? result[i - 1][j]     : 0);
                unsigned int sum2   =   ((j > 0) ? result[i][j - 1]     : 0);
                unsigned int sum3   =   ((m > 0) ? result[i - 1][j - 1] : 0);

                result[i][j] = matrix[i][j] + sum1 + sum2 - sum3;
            }
        }
    }
}

void generateSuffixSumsMatrix(unsigned int matrix[MAX_ROWS][MAX_COLS], unsigned int result[MAX_ROWS][MAX_COLS], unsigned int rows, unsigned int cols) {
    for (long long i = rows - 1; i >= 0; --i) {
        for (long long j = cols - 1; j >= 0; --j) {
            if (i == rows - 1 && j == cols - 1) {
                result[i][j] = matrix[i][j];
            } else {
                unsigned int sum1   =   ((i < rows - 1) ? result[i + 1][j]                      : 0);
                unsigned int sum2   =   ((j < cols - 1) ? result[i][j + 1]                      : 0);
                unsigned int sum3   =   ((i < rows - 1 && j < cols - 1) ? result[i + 1][j + 1]  : 0);

                result[i][j] = matrix[i][j] + sum1 + sum2 - sum3;
            }
        }
    }
}



void solutionArray() {
    putchar('\n');
    putchar('\n');
    putchar('\n');

    unsigned int array[MAX_ELMS]    =   { 0 };

    unsigned int size = readSize1(MAX_ELMS);

    inputArray(array, size);
    printArray(array, size);


    unsigned int result1[MAX_ELMS]  =   { 0 };
    unsigned int result2[MAX_ELMS]  =   { 0 };

    generatePrefixSumsArray(array, result1, size);
    generateSuffixSumsArray(array, result2, size);

    printf("Generating Prefix Sums... ");   printArray(result1, size);
    printf("Generating Suffix Sums... ");   printArray(result2, size);

    putchar('\n');
    putchar('\n');
    putchar('\n');
}

void solutionMatrix() {
    putchar('\n');
    putchar('\n');
    putchar('\n');
    
    unsigned int matrix[MAX_ROWS][MAX_COLS]     =   { { 0 } };

    unsigned int rows = readSize2(MAX_ROWS, "ROWS");
    unsigned int cols = readSize2(MAX_COLS, "COLS");

    inputMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols);

    unsigned int result1[MAX_ROWS][MAX_COLS]    =   { { 0 } };
    unsigned int result2[MAX_ROWS][MAX_COLS]    =   { { 0 } };

    generatePrefixSumsMatrix(matrix, result1, rows, cols);
    generateSuffixSumsMatrix(matrix, result2, rows, cols);

    printf("Generating Prefix Sums... ");   printMatrix(result1, rows, cols);
    printf("Generating Suffix Sums... ");   printMatrix(result2, rows, cols);

    putchar('\n');
    putchar('\n');
    putchar('\n');
}
