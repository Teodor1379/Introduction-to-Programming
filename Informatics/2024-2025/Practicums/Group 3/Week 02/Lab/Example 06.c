#include <math.h>

#include <stdio.h>



#define EPSILON 1e-9



int main() {
    double number1 = 0.0;
    double number2 = 0.0;

    printf("Enter the NUMBER 1: "); scanf("%lf",    &number1);
    printf("Enter the NUMBER 2: "); scanf("%lf",    &number2);

    int condition = fabs(number1 - number2) < EPSILON;

    printf("Are the numbers equal: %d\n", condition);

    return 0;
}
