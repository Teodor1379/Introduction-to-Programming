#include <stdio.h>



double findSumProgression(double a, double d, unsigned int n) {
    return (2 * a + (n - 1) * d) * n / 2;
}

void showProgressionInformation(double a, double d, unsigned int n) {
    printf("The content of the progression is: ");

    for (unsigned int i = 1; i <= n; ++i) {
        printf("%lf ", a);

        a = a + d;
    }

    printf("\nThe sum of the progression is: %lf\n", findSumProgression(a - n * d, d, n));
}



int main() {
    double  a   =   0.0;
    double  d   =   0.0;

    printf("Enter the number A: "); if (scanf("%lf", &a) != 1)  { puts("Invalid Input!");   return 1;   }
    printf("Enter the number D: "); if (scanf("%lf", &d) != 1)  { puts("Invalid Input!");   return 1;   }


    unsigned int n  =   0;

    do {
        printf("Enter the number N: ");

        if (scanf("%u", &n) != 1) {
            puts("Invalid Input!");

            return 1;
        }
    } while (n == 0);


    showProgressionInformation(a, d, n);


    return 0;
}
