#include <math.h>

#include <stdio.h>



int main() {
    double number1 = 0.0;
    double number2 = 0.0;
    double number3 = 0.0;

    printf("Enter Number 1: "); scanf("%lf", &number1);
    printf("Enter Number 2: "); scanf("%lf", &number2);
    printf("Enter Number 3: "); scanf("%lf", &number3);


    double arithmeticMean   =   (number1 + number2 + number3) / 3.0                                 ;
    double geometricMean    =   cbrt(number1 * number2 * number3)                                   ;
    double harmonicMean     =   3.0 / ((1.0 / number1) + (1.0 / number2) + (1.0 / number3))         ;
    double quadraticMean    =   sqrt((pow(number1, 2) + pow(number2, 2) + pow(number3, 2)) / 3.0)   ;

    printf("The arithmetic  mean is: %lf\n",    arithmeticMean  );
    printf("The geometric   mean is: %lf\n",    geometricMean   );
    printf("The harmonic    mean is: %lf\n",    harmonicMean    );
    printf("The quadratic   mean is: %lf\n",    quadraticMean   );


    return 0;
}
