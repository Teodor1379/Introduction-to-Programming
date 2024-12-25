#include <stdio.h>



int main() {
    unsigned long long  n   =   0   ;
    double              x   =   0.0 ;
    double              r   =   1.0 ;

    printf("Enter the number N: "); if (scanf("%llu", &n) != 1) { puts("Invalid Input!");   return 1;   }
    printf("Enter the number X: "); if (scanf("%lf",  &x) != 1) { puts("Invalid Input!");   return 1;   }


    for (unsigned long long i = 1; i <= n; ++i) {
        r = r * x;
    }

    printf("The result is: %lf\n", r);


    return 0;
}
