#include <stdio.h>



const double PI = 3.14;



int main() {
    double r = 0.0;


    printf("Enter the radius of the circle: ");

    scanf("%lf", &r);


    double c = 2 * PI * r;
    double s = PI * r * r;


    printf("The circumference   of the circle is: %lf\n", c);
    printf("The area            of the circle is: %lf\n", s);


    return 0;
}
