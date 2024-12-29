#include <assert.h>

#include <stdio.h>



#define MAX_SIZE 9
#define MIN_NUMB 0
#define MAX_NUMB 9



void clearStandardInput();



unsigned int    readElem();




void inputBoard(unsigned int board[MAX_SIZE][MAX_SIZE]);
void printBoard(unsigned int board[MAX_SIZE][MAX_SIZE]);



int validateSingleRow(unsigned int board[MAX_SIZE][MAX_SIZE], unsigned int index                        );
int validateSingleCol(unsigned int board[MAX_SIZE][MAX_SIZE], unsigned int index                        );
int validateSingleSqr(unsigned int board[MAX_SIZE][MAX_SIZE], unsigned int index1, unsigned int index2  );



int validateRows(unsigned int board[MAX_SIZE][MAX_SIZE]);
int validateCols(unsigned int board[MAX_SIZE][MAX_SIZE]);
int validateSqrs(unsigned int board[MAX_SIZE][MAX_SIZE]);



int validateBoard(unsigned int board[MAX_SIZE][MAX_SIZE]);



int main() {
    unsigned int board[MAX_SIZE][MAX_SIZE] = { { 0 } };

    inputBoard(board);
    printBoard(board);

    printf("Is the SUDOKU board valid: %s\n", validateBoard(board) ? "Yes" : "No");

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
    } while (inputArgument != 1 || elem > MAX_NUMB);

    return elem;
}



void inputBoard(unsigned int board[MAX_SIZE][MAX_SIZE]) {
    printf("Enter the elements of the SUDOKU board:\n");

    for (unsigned int i = 0; i < MAX_SIZE; ++i) {
        for (unsigned int j = 0; j < MAX_SIZE; ++j) {
            board[i][j] = readElem();
        }
    }
}

void printBoard(unsigned int board[MAX_SIZE][MAX_SIZE]) {
    printf("The elements of the SUDOKU board are:\n");

    for (unsigned int i = 0; i < MAX_SIZE; ++i) {
        for (unsigned int j = 0; j < MAX_SIZE; ++j) {
            printf("%d ", board[i][j]);
        }

        putchar('\n');
    }
}



int validateSingleRow(unsigned int board[MAX_SIZE][MAX_SIZE], unsigned int index) {
    assert(index < MAX_SIZE     );

    unsigned int buffer[10] = { 0 };

    for (unsigned int i = 0; i < MAX_SIZE; ++i) {
        unsigned int element = board[index][i];
        buffer[element] = buffer[element] + 1;

        if (element != 0 && buffer[element] == 2) {
            return 0;
        }
    }

    return 1;
}

int validateSingleCol(unsigned int board[MAX_SIZE][MAX_SIZE], unsigned int index) {
    assert(index < MAX_SIZE     );

    unsigned int buffer[10] = { 0 };

    for (unsigned int i = 0; i < MAX_SIZE; ++i) {
        unsigned int element = board[i][index];
        buffer[element] = buffer[element] + 1;

        if (element != 0 && buffer[element] == 2) {
            return 0;
        }
    }

    return 1;
}

int validateSingleSqr(unsigned int board[MAX_SIZE][MAX_SIZE], unsigned int index1, unsigned int index2) {
    assert(index1 < MAX_SIZE    );
    assert(index2 < MAX_SIZE    );

    unsigned int buffer[10] = { 0 };

    for (unsigned int i = index1 - 1; i <= index1 + 1; ++i) {
        for (unsigned int j = index2 - 1; j <= index2 + 1; ++j) {
            unsigned int element = board[i][j];
            buffer[element] = buffer[element] + 1;

            if (element != 0 && buffer[element] == 2) {
                return 0;
            }
        }
    }

    return 1;
}



int validateRows(unsigned int board[MAX_SIZE][MAX_SIZE]) {
    for (unsigned int i = 0; i < MAX_SIZE; ++i) {
        if (validateSingleRow(board, i) == 0) {
            return 0;
        }
    }

    return 1;
}

int validateCols(unsigned int board[MAX_SIZE][MAX_SIZE]) {
    for (unsigned int i = 0; i < MAX_SIZE; ++i) {
        if (validateSingleCol(board, i) == 0) {
            return 0;
        }
    }

    return 1;
}

int validateSqrs(unsigned int board[MAX_SIZE][MAX_SIZE]) {
    for (unsigned int i = 1; i < MAX_SIZE; i += 3) {
        for (unsigned int j = 1; j < MAX_SIZE; j += 3) {
            if (validateSingleSqr(board, i, j) == 0) {
                return 0;
            }
        }
    }

    return 1;
}



int validateBoard(unsigned int board[MAX_SIZE][MAX_SIZE]) {
    return  validateRows(board) &&
            validateCols(board) &&
            validateSqrs(board);
}
