#include <math.h>

#include <stdio.h>



const double EPSILON    =   1e-9;



int main() {
    double rectangle1X1 =   0.0;
    double rectangle1Y1 =   0.0;
    double rectangle1X2 =   0.0;
    double rectangle1Y2 =   0.0;

    double rectangle2X1 =   0.0;
    double rectangle2Y1 =   0.0;
    double rectangle2X2 =   0.0;
    double rectangle2Y2 =   0.0;


    printf("Enter the coordinates of Rectangle 1: ");
    
    if (scanf("%lf %lf %lf %lf", &rectangle1X1, &rectangle1Y1, &rectangle1X2, &rectangle1Y2) != 4) {
        puts("Invalid Input!");

        return 1;
    }

    if (rectangle1X2 < rectangle1X1 || rectangle1Y2 < rectangle1Y2) {
        puts("Invalid Coordinates for Rectangle!");

        return 2;
    }


    printf("Enter the coordinates of Rectangle 2: ");
    
    if (scanf("%lf %lf %lf %lf", &rectangle2X1, &rectangle2Y1, &rectangle2X2, &rectangle2Y2) != 4) {
        puts("Invalid Input!");

        return 1;
    }

    if (rectangle2X2 < rectangle2X1 || rectangle2Y2 < rectangle2Y1) {
        puts("Invalid Coordinates for Rectangle!");

        return 2;
    }


    unsigned int conditionOverlap1  =   (rectangle2X1 < rectangle1X2 && rectangle2X2 > rectangle1X1);
    unsigned int conditionOverlap2  =   (rectangle2Y1 < rectangle1Y2 && rectangle2Y2 > rectangle1Y1);

    printf("Do the rectangles overlap: %s\n", conditionOverlap1 && conditionOverlap2 ? "Yes" : "No");

    return 0;
}
