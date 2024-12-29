#include <math.h>

#include <stdio.h>



int main() {
    double area = 0.0;

    printf("Enter the area of the triangle: ");

    scanf("%lf", &area);

    
    double side = sqrt((area * 4) / sqrt(3));

    printf("The side of the triangle is: %lf\n", side);


    return 0;
}
