#include <math.h>

#include <stdio.h>



#define EPSILON 1e-9



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

    printf("Enter the number A: "); if (scanf("%lf", &a) != 1)  { puts("Invalid Input!");   return 1;   }
    printf("Enter the number Q: "); if (scanf("%lf", &q) != 1)  { puts("Invalid Input!");   return 1;   }


    if (fabs(q) < EPSILON) {
        printf("Invalid value for Q!\n");

        return 1;
    }


    unsigned int n  =   0;

    do {
        printf("Enter the number N: ");

        if (scanf("%u", &n) != 1) {
            puts("Invalid Input!");

            return 1;
        }
    } while (n == 0);


    showProgressionInformation(a, q, n);


    return 0;
}
