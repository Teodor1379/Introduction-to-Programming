#include <math.h>

#include <stdio.h>

#define PI      3.14
#define EPSILON 1e-9

double equalNumbers(double number1, double number2) {
    return fabs(number1 - number2) < EPSILON;
}

double minSides(double side1, double side2, double side3) {
    double minSide = side1 + side2 + side3;

    if (minSide >= side1)   {   minSide = side1;    }
    if (minSide >= side2)   {   minSide = side2;    }
    if (minSide >= side3)   {   minSide = side3;    }

    return minSide;
}

double maxSides(double side1, double side2, double side3) {
    double maxSide = -1;

    if (maxSide <= side1)   {   maxSide = side1;    }
    if (maxSide <= side2)   {   maxSide = side2;    }
    if (maxSide <= side3)   {   maxSide = side3;    }

    return maxSide;
}

double avgSides(double side1, double side2, double side3) {
    return  side1 + side2 + side3
            - minSides(side1, side2, side3)
            - maxSides(side1, side2, side3);
}


int existsTriangle(double side1, double side2, double side3) {
    return  side1 < side2 + side3   &&
            side2 < side1 + side3   &&
            side3 < side1 + side2   &&
            
            side1 >= 0.0            &&
            side2 >= 0.0            &&
            side3 >= 0.0            ;
}

double perimeterTriangle(double side1, double side2, double side3) {
    return side1 + side2 + side3;
}

double areaTriangle(double side1, double side2, double side3) {
    double component1   =   perimeterTriangle(side1, side2, side3) / 2;
    double component2   =   component1 - side1;
    double component3   =   component1 - side2;
    double component4   =   component1 - side3;
    
    return sqrt(component1 * component2 * component3 * component4);
}

double isTriangleEquilateral(double side1, double side2, double side3) {
    return  equalNumbers(side1, side2)  &&
            equalNumbers(side2, side3);
}

double isTriangleRight(double side1, double side2, double side3) {
    return  equalNumbers(side1 * side1 + side2 * side2, side3 * side3)  ||
            equalNumbers(side2 * side2 + side3 * side3, side1 * side1)  ||
            equalNumbers(side3 * side3 + side1 * side1, side2 * side2);
}

double calculateAngleTriangle(double side1, double side2) {
    return  atan(side1 / side2) * (180.0 / PI);
}

void triangleInformation(double side1, double side2, double side3) {
    printf("Side 1 of the triangle is: %lf\n",  side1);
    printf("Side 2 of the triangle is: %lf\n",  side2);
    printf("Side 3 of the triangle is: %lf\n",  side3);

    printf("The perimeter   of the triangle is: %lf\n", perimeterTriangle(side1, side2, side3)  );
    printf("The area        of the triangle is: %lf\n", areaTriangle(side1, side2, side3)       );
}

void equilateralTriangleInformation(double side1, double side2, double side3) {
    printf("Side 1 of the triangle is: %lf\n",  side1);
    printf("Side 2 of the triangle is: %lf\n",  side2);
    printf("Side 3 of the triangle is: %lf\n",  side3);

    printf("The perimeter   of the triangle is: %lf\n", perimeterTriangle(side1, side2, side3)  );
    printf("The area        of the triangle is: %lf\n", areaTriangle(side1, side2, side3)       );
    printf("The height      of the triangle is: %lf\n", sqrt(3) * side1 / 2                     );
    printf("The median      of the triangle is: %lf\n", sqrt(3) * side2 / 2                     );
    printf("The bisector    of the triangle is: %lf\n", sqrt(3) * side3 / 2                     );

    printf("The radius of the incircle is: %lf\n",  sqrt(3) * side1 / 6 );
    printf("The radius of the excircle is: %lf\n",  sqrt(3) * side3 / 3 );
}

void rightTriangleInformation(double side1, double side2, double side3) {
    printf("Side 1 of the triangle is: %lf\n",  side1);
    printf("Side 2 of the triangle is: %lf\n",  side2);
    printf("Side 3 of the triangle is: %lf\n",  side3);

    printf("The perimeter   of the triangle is: %lf\n", perimeterTriangle(side1, side2, side3)  );
    printf("The area        of the triangle is: %lf\n", areaTriangle(side1, side2, side3)       );

    printf("Angle 1 of the triangle is: %lf\n", 90.0                                                                                );
    printf("Angle 2 of the triangle is: %lf\n", calculateAngleTriangle(avgSides(side1, side2, side3), minSides(side1, side2, side3)));
    printf("Angle 3 of the triangle is: %lf\n", calculateAngleTriangle(minSides(side1, side2, side3), avgSides(side1, side2, side3)));
}

int main() {
    double  side1   =   0.0;
    double  side2   =   0.0;
    double  side3   =   0.0;

    do {
        printf("Enter the size of Side 1: ");

        scanf("%lf", &side1);

        while (getchar() != '\n');
    } while (side1 < 0 || equalNumbers(side1, 0.0));

    do {
        printf("Enter the size of Side 2: ");

        scanf("%lf", &side2);

        while (getchar() != '\n');
    } while (side2 < 0 || equalNumbers(side2, 0.0));

    do {
        printf("Enter the size of Side 3: ");

        scanf("%lf", &side3);

        while (getchar() != '\n');
    } while (side3 < 0 || equalNumbers(side3, 0.0));

    if (existsTriangle(side1, side2, side3)) {
        if (isTriangleEquilateral(side1, side2, side3)) {
            equilateralTriangleInformation(side1, side2, side3);
        } else if (isTriangleRight(side1, side2, side3)) {
            rightTriangleInformation(side1, side2, side3);
        } else {
            triangleInformation(side1, side2, side3);
        }
    } else {
        puts("There is no such triangle!");
    }

    return 0;
}
