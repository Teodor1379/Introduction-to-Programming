#include <stdio.h>



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



int factorial(int n) {
    int result = 1;

    for (int i = 1; i <= n; ++i) {
        result = result * i;
    }

    return result;
}

int binomial(int n, int k) {
    int numerator   =   factorial(n);
    int denominator =   factorial(k) * factorial(n - k);

    return numerator / denominator;
}



void printTriangleRow(int n) {
    for (int k = 0; k <= n; ++k) {
        printf("%d ", binomial(n, k));
    }

    putchar('\n');
}



int main() {
    int number = 0;

    do {
        printf("Enter the number N: ");

        if (scanf("%d", &number) != 1) {
            puts("Invalid Input!");

            clearStandardInput();
        }
    } while (number < 0);


    printf("The triangle row is: ");

    printTriangleRow(number);


    return 0;
}
