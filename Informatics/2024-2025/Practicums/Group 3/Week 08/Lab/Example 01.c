#include <stdio.h>



int main() {
    int matrix1[3][7] = { { 0 } };

    int matrix2[2][3] = { { 1, 2, 3 }, { 4, 5, 6 }};

    int matrix3[3][3] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int matrix4[][2] = { 1, 2, 3, 4 };


    printf("The elements of the matrix 1 is:\n");

    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < 7; ++j) {
            printf("%d ", matrix1[i][j]);
        }

        putchar('\n');
    }


    printf("The elements of the matrix 2 is:\n");

    for (unsigned int i = 0; i < 2; ++i) {
        for (unsigned int j = 0; j < 3; ++j) {
            printf("%d ", matrix2[i][j]);
        }

        putchar('\n');
    }


    printf("The elements of the matrix 3 is:\n");

    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < 3; ++j) {
            printf("%d ", matrix3[i][j]);
        }

        putchar('\n');
    }


    printf("The elements of the matrix 4 is:\n");

    for (unsigned int i = 0; i < 2; ++i) {
        for (unsigned int j = 0; j < 2; ++j) {
            printf("%d ", matrix4[i][j]);
        }

        putchar('\n');
    }


    return 0;
}



// warning: missing braces around initializer [-Wmissing-braces]
