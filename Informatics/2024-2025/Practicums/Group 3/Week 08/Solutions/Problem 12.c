#include <assert.h>

#include <stdio.h>



#define MAX_ROWS 9
#define MAX_COLS 9



void clearStandardInput();



char    readElem();



void inputChess(char board[MAX_ROWS][MAX_COLS]);
void printChess(char board[MAX_ROWS][MAX_COLS]);



int countQueensRow(char board[MAX_ROWS][MAX_COLS], unsigned int index);
int countQueensCol(char board[MAX_ROWS][MAX_COLS], unsigned int index);



int countQueensDiagonal1(char board[MAX_ROWS][MAX_COLS]);
int countQueensDiagonal2(char board[MAX_ROWS][MAX_COLS]);



int validateChessBoard(char board[MAX_ROWS][MAX_COLS]);



int main() {
    char board[MAX_ROWS][MAX_COLS];

    inputChess(board);
    printChess(board);

    printf("Is the chess board valid: %s\n", validateChessBoard(board) ? "Yes" : "No");

    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



char readElem() {
    char elem           =   0;

    do {
        elem = getchar();
    } while (elem != 'Q' && elem != 'O');

    return elem;
}



void inputChess(char board[MAX_ROWS][MAX_COLS]) {
    printf("Enter the chess board:\n");

    for (unsigned int i = 0; i < MAX_ROWS; ++i) {
        for (unsigned int j = 0; j < MAX_COLS; ++j) {
            board[i][j] = readElem();
        }
    }
}

void printChess(char board[MAX_ROWS][MAX_COLS]) {
    printf("The chess board is:\n");

    for (unsigned int i = 0; i < MAX_ROWS; ++i) {
        for (unsigned int j = 0; j < MAX_COLS; ++j) {
            printf("%c ", board[i][j]);
        }

        putchar('\n');
    }
}



int countQueensRow(char board[MAX_ROWS][MAX_COLS], unsigned int index) {
    assert(index < MAX_ROWS );

    unsigned int counter = 0;

    for (unsigned int i = 0; i < MAX_COLS; ++i) {
        if (board[i][index] == 'Q') {
            counter = counter + 1;
        }
    }

    return counter <= 1;
}

int countQueensCol(char board[MAX_ROWS][MAX_COLS], unsigned int index) {
    assert(index < MAX_COLS );

    unsigned int counter = 0;

    for (unsigned int i = 0; i < MAX_ROWS; ++i) {
        if (board[index][i] == 'Q') {
            counter = counter + 1;
        }
    }

    return counter <= 1;
}



int countQueensDiagonal1(char board[MAX_ROWS][MAX_COLS]) {
    for (long long j = 0; j < MAX_COLS; ++j) {
        long long row   =   0   ;
        long long col   =   j   ;

        unsigned int result = 0;

        while (row < MAX_ROWS && col < MAX_COLS) {
            if (board[row][col] == 'Q') {
                result = result + 1;
            }

            row = row + 1;
            col = col + 1;
        }

        if (result > 1) {
            return 0;
        }
    }

    for (long long i = 1; i < MAX_ROWS; ++i) {
        long long row   =   i;
        long long col   =   0;

        unsigned int result = 0;

        while (row < MAX_ROWS && col < MAX_COLS) {
            if (board[row][col] == 'Q') {
                result = result + 1;
            }

            row = row + 1;
            col = col + 1;
        }

        if (result > 1) {
            return 0;
        }
    }

    return 1;
}

int countQueensDiagonal2(char board[MAX_ROWS][MAX_COLS]) {
    for (long long i = 0; i < MAX_COLS; ++i) {
        long long row   =   MAX_COLS - 1    ;
        long long col   =   i               ;

        unsigned int result = 0;

        while (row >= 0 && col < MAX_COLS) {
            if (board[row][col] == 'Q') {
                result = result + 1;
            }

            row = row - 1;
            col = col + 1;
        }

        if (result > 1) {
            return 0;
        } 
    }

    for (long long i = MAX_ROWS - 2; i >= 0; --i) {
        long long row   =   i           ; 
        long long col   =   MAX_ROWS - 1;

        unsigned int result = 0;

        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') {
                result = result + 1;
            }

            row = row - 1;
            col = col + 1;
        }

        if (result > 1) {
            return 0;
        }
    }

    return 1;
}



int validateChessBoard(char board[MAX_ROWS][MAX_COLS]) {
    for (unsigned int i = 0; i < MAX_ROWS; ++i) {
        if (countQueensRow(board, i) == 0) {
            return 0;
        }
    }

    for (unsigned int i = 0; i < MAX_COLS; ++i) {
        if (countQueensCol(board, i) == 0) {
            return 0;
        }
    }

    int result1 =   countQueensDiagonal1(board);
    int result2 =   countQueensDiagonal2(board);

    return result1 && result2;
}
