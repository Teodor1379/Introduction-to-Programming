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



void printCharacter(char character, int n) {
    if (n == 1) {
        printf("%c", character);
    } else {
        printf("%c^%d", character, n);
    }
}

void printExpression(int n) {
    for (int k = 0; k <= n; ++k) {
        if (k == 0) {
            printCharacter('a', n);
            printf(" + ");
        } else if (k == n) {
            printCharacter('b', n);
        } else {
            printf("%d * ", binomial(n, k));

            printCharacter('a', n - k);
            printf(" * ");
            printCharacter('b', k);
            printf(" + ");
        }
    }
}


int main() {
    int power = 0;

    printf("Enter the power: ");

    if (scanf("%d", &power) != 1) {
        puts("Invalid Input!");

        clearStandardInput();

        return 1;
    }


    if (power > 0) {
        printExpression(power);

        putchar('\n');
    } else if (power < 0) {
        printf("1/");

        putchar('(');
        printExpression(-power);
        putchar(')');

        putchar('\n');
    } else {
        printf("1");
    
        putchar('\n');
    }


    return 0;
}
