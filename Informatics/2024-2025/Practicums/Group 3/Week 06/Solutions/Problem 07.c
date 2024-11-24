#include <math.h>

#include <stdio.h>

double findSumProgression(double a, double q, unsigned int n) {
    return a * (1 - pow(q, n)) / (1 - q);
}

void showProgressionInformation(double a, double q, unsigned int n) {
    printf("The content of the progression is: ");

    for (unsigned int i = 1; i <= n; ++i) {
        printf("%lf ", a);

        a = a * q;
    }

    printf("\nThe sum of the progression is: %lf\n", findSumProgression(a, q, n));
}

int main() {
    double  a   =   0.0;
    double  q   =   0.0;

    printf("Enter the number A: "); scanf("%lf", &a);
    printf("Enter the number Q: "); scanf("%lf", &q);

    unsigned int n  =   0;

    do {
        printf("Enter the number N: ");
        scanf("%u", &n);
    } while (n == 0);

    showProgressionInformation(a, q, n);

    return 0;
}
