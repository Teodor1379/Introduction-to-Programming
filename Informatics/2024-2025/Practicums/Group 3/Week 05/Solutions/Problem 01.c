#include <stdio.h>

void solutionOne    ();
void solutionTwo    ();
void solutionThree  ();
void solutionFour   ();
void solutionFive   ();
void solutionSix    ();
void solutionSeven  ();
void solutionEight  ();
void solutionNine   ();

int main() {
    solutionOne     ();
    solutionTwo     ();
    solutionThree   ();
    solutionFour    ();
    solutionFive    ();
    solutionSix     ();
    solutionSeven   ();
    solutionEight   ();
    solutionNine    ();

    return 0;
}

void solutionOne() {
    long long n = 0;

    do {
        printf("Enter the number N: ");

        scanf("%lld", &n);
    } while (n < 0);

    long long result = 0;

    for (long long i = 1; i <= n; ++i) {
        result = result + i;
    }

    printf("The result is: %lld\n", result);
}

void solutionTwo() {
    long long n = 0;

    do {
        printf("Enter the number N: ");

        scanf("%lld", &n);
    } while (n < 0);

    long long result = 0;

    for (long long i = 1; i <= n; ++i) {
        result = result + (i * i);
    }

    printf("The result is: %lld\n", result);
}

void solutionThree() {
    long long n = 0;

    do {
        printf("Enter the number N: ");

        scanf("%lld", &n);
    } while (n < 0);

    long long result = 0;

    for (long long i = 1; i <= n; ++i) {
        result = result + (i * i * i);
    }

    printf("The result is: %lld\n", result);
}

void solutionFour() {
    long long n = 0;

    do {
        printf("Enter the number N: ");

        scanf("%lld", &n);
    } while (n < 0);

    long long result = 0;

    for (long long i = 1; i <= n; ++i) {
        result = result + (i * (i + 1));
    }

    printf("The result is: %lld\n", result);
}

void solutionFive() {
    long long n = 0;

    do {
        printf("Enter the number N: ");

        scanf("%lld", &n);
    } while (n < 0);

    long long result = 0;

    for (long long i = 2; i <= 2 * n; i = i + 2) {
        result = result + ((i - 1) * i);
    }

    printf("The result is: %lld\n", result);
}

void solutionSix() {
    long long n = 0;

    do {
        printf("Enter the number N: ");

        scanf("%lld", &n);
    } while (n < 0);

    long long result = 0;

    for (long long i = 1; i <= n; ++i) {
        result = result + (i * (i + 1) * (i + 2));
    }

    printf("The result is: %lld\n", result);
}

void solutionSeven() {
    long long n = 0;

    do {
        printf("Enter the number N: ");

        scanf("%lld", &n);
    } while (n < 0);

    long long result = 1;

    for (long long i = n; i >= 1; --i) {
        result = result * i;
    }

    printf("The result is: %lld\n", result);
}

void solutionEight() {
    long long n = 0;

    do {
        printf("Enter the number N: ");

        scanf("%lld", &n);
    } while (n < 0);

    long long result = 1;

    for (long long i = n; i >= 1; i = i - 2) {
        result = result * i;
    }

    printf("The result is: %lld\n", result);
}

void solutionNine() {
    long long n = 0;

    do {
        printf("Enter the number N: ");

        scanf("%lld", &n);
    } while (n < 0);

    long long result = 1;

    for (long long i = n; i >= 1; i = i - 3) {
        result = result * i;
    }

    printf("The result is: %lld\n", result);
}
