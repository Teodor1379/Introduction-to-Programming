#include <stdio.h>



int main() {
    double  X   =   0.0;
    double  Y   =   0.0;

    printf("Enter the X: ");    scanf("%lf",    &X);
    printf("Enter the Y: ");    scanf("%lf",    &Y);


    double fraction1    =   (X * X) / (Y * Y - 1);
    double fraction2    =   (Y * Y) / (X * X - 1);
    double fraction3    =   1 / (X * X + Y * Y);
    double fraction4    =   1 / (X * X - Y * Y);


    double result = (fraction1 + fraction2 + fraction3) / fraction4;

    printf("The result of the calculation is: %lf\n",   result);


    return 0;
}
