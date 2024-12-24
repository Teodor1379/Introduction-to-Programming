#include <math.h>

#include <stdio.h>

#include <stdbool.h>



const double EPSILON    =   1e-9;



void dimensionOne() {
    double  x   =   0.0;

    printf("Enter the X coordinate: "); scanf("%lf", &x);


    bool    isXEqualZero    =   (fabs(x) < EPSILON);


    if (isXEqualZero) {
        puts("The point is on the Abscissa!");
    } else {
        if (x > 0.0) {
            puts("The point is in 1 Semi-Plane!");
        } else {
            puts("The point is in 2 Semi-Plane!");
        }
    }
}

void dimensionTwo() {
    double  x   =   0.0;
    double  y   =   0.0;

    printf("Enter the X coordinate: "); scanf("%lf", &x);
    printf("Enter the Y coordinate: "); scanf("%lf", &y);


    bool    isXEqualZero    =   (fabs(x) < EPSILON);
    bool    isYEqualZero    =   (fabs(y) < EPSILON);


    if (isXEqualZero && isYEqualZero) {
        puts("The point is on the Center!");
    } else {
        if (isYEqualZero) {
            puts("The point is on the Abscissa!");
        } else if (isXEqualZero) {
            puts("The point is on the Ordinate!");
        } else {
            if (x > 0.0 && y > 0.0) {
                puts("The point is in 1 Quadrant!");
            } else if (x < 0.0 && y > 0.0) {
                puts("The point is in 2 Quadrant!");
            } else if (x < 0.0 && y < 0.0) {
                puts("The point is in 3 Quadrant!");
            } else {
                puts("The point is in 4 Quadrant!");
            }
        }
    }
}

void dimensionThree() {
    double  x   =   0.0;
    double  y   =   0.0;
    double  z   =   0.0;

    printf("Enter the X coordinate: "); scanf("%lf", &x);
    printf("Enter the Y coordinate: "); scanf("%lf", &y);
    printf("Enter the Z coordinate: "); scanf("%lf", &z);


    bool    isXEqualZero    =   (fabs(x) < EPSILON);
    bool    isYEqualZero    =   (fabs(y) < EPSILON);
    bool    isZEqualZero    =   (fabs(z) < EPSILON);


    if (isXEqualZero && isYEqualZero && isZEqualZero) {
        puts("The point is on the Center!");
    } else {
        if (isZEqualZero) {
            if (isYEqualZero) {
                puts("The point is on the Abscissa!");
            } else if (isXEqualZero) {
                puts("The point is on the Ordinate!");
            } else {
                puts("The point is in the Semi-Plane Oxy!");
            }
        } else if (isYEqualZero) {
            if (isZEqualZero) {
                puts("The point is on the Abscissa!");
            } else if (isXEqualZero) {
                puts("The point is on the Applicate!");
            } else {
                puts("The point is in the Semi-Plane Oxz!");
            }
        } else if (isXEqualZero) {
            if (isZEqualZero) {
                puts("The point is on the Ordinate!");
            } else if (isYEqualZero) {
                puts("The point is on the Applicate!");
            } else {
                puts("The point is in the Semi-Plane Oyz!");
            }
        } else {
            if (x > 0.0 && y < 0.0 && z > 0.0) {
                puts("The point is in 1 Octant!");
            } else if (x < 0.0 && y < 0.0 && z > 0.0) {
                puts("The point is in 2 Octant!");
            } else if (x < 0.0 && y > 0.0 && z > 0.0) {
                puts("The point is in 3 Octant!");
            } else if (x > 0.0 && y > 0.0 && z > 0.0) {
                puts("The poins in in 4 Octant!");
            } else if (x > 0.0 && y < 0.0 && z < 0.0) {
                puts("The point is in 5 Octant!");
            } else if (x < 0.0 && y < 0.0 && z < 0.0) {
                puts("The point is in 6 Octant!");
            } else if (x < 0.0 && y > 0.0 && z < 0.0) {
                puts("The point is in 7 Octant!");
            } else {
                puts("The point is in 8 Octant!");
            }
        }
    }
}



int main() {
    dimensionOne    ();
    dimensionTwo    ();
    dimensionThree  ();

    return 0;
}