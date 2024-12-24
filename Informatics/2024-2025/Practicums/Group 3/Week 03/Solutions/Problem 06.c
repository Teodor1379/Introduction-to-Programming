#include <math.h>

#include <stdio.h>



const double EPSILON    =   1e-9;



int main() {
    double xCenter  =   0.0;
    double yCenter  =   0.0;

    printf("Enter the coordinates of the center of the circle: ");
    
    if (scanf("%lf %lf", &xCenter, &yCenter) != 2) {
        puts("Invalid Input!");

        return 1;
    }


    double radius   =   0.0;

    printf("Enter the radius of the circle: ");
    
    if (scanf("%lf", &radius) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    double xPoint   =   0.0;
    double yPoint   =   0.0;

    printf("Enter the coordinates of the point: ");
    
    if (scanf("%lf %lf", &xPoint, &yPoint) != 2) {
        puts("Invalid Input!");

        return 1;
    }


    double xDistance    =   pow(fabs(xPoint - xCenter), 2);
    double yDistance    =   pow(fabs(yPoint - yCenter), 2);
    double  distance    =   sqrt(xDistance + yDistance);

    if (fabs(distance - radius) <= EPSILON) {
        printf("On the circle!\n");
    } else {
        if (distance < radius) {
            printf("Inside the Circle!\n");
        } else {
            printf("Outside the Circle!\n");
        }
    }


    return 0;
}
