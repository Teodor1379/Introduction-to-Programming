#include <stdio.h>

int main() {
    unsigned long long  n   =   0   ;
    double              x   =   0.0 ;
    double              r   =   1.0 ;

    printf("Enter the number N: "); scanf("%llu", &n);
    printf("Enter the number X: "); scanf("%lf",  &x);

    for (unsigned long long i = 1; i <= n; ++i) {
        r = r * x;
    }

    printf("The result is: %lf\n", r);

    return 0;
}
