#include <math.h>

#include <stdio.h>



#define EPSILON 1e-9



int main() {
    double x0   =   0.0;
    double x1   =   0.0;
    double x2   =   0.0;
    double x3   =   0.0;

    double y0   =   0.0;
    double y1   =   0.0;
    double y2   =   0.0;
    double y3   =   0.0;

    printf("Enter the coordinates of the point: "); if (scanf("%lf %lf", &x0, &y0) != 2)    { puts("Invalid Input!");   return 1;   }

    printf("Enter the coordinates of Vertex 1: ");  if (scanf("%lf %lf", &x1, &y1) != 2)    { puts("Invalid Input!");   return 1;   }
    printf("Enter the coordinates of Vertex 2: ");  if (scanf("%lf %lf", &x2, &y2) != 2)    { puts("Invalid Input!");   return 1;   }
    printf("Enter the coordinates of Vertex 3: ");  if (scanf("%lf %lf", &x3, &y3) != 2)    { puts("Invalid Input!");   return 1;   }


    double destination01    =   sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));
    double destination02    =   sqrt(pow(x2 - x0, 2) + pow(y2 - y0, 2));
    double destination03    =   sqrt(pow(x3 - x0, 2) + pow(y3 - y0, 2));

    double side1    =   sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    double side2    =   sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double side3    =   sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));


    double halfPerimiter0   =   (side1 + side2 + side3) / 2.0;

    double halfPerimeter1   =   (destination01 + destination02 + side1) / 2.0;
    double halfPerimeter2   =   (destination02 + destination03 + side2) / 2.0;
    double halfPerimeter3   =   (destination03 + destination01 + side3) / 2.0;


    double area0    =   sqrt(halfPerimiter0 * (halfPerimiter0 - side1) * (halfPerimiter0 - side2) * (halfPerimiter0 - side3));

    double area1    =   sqrt(halfPerimeter1 * (halfPerimeter1 - destination01) * (halfPerimeter1 - destination02) * (halfPerimeter1 - side1));
    double area2    =   sqrt(halfPerimeter2 * (halfPerimeter2 - destination02) * (halfPerimeter2 - destination03) * (halfPerimeter2 - side2));
    double area3    =   sqrt(halfPerimeter3 * (halfPerimeter3 - destination03) * (halfPerimeter3 - destination01) * (halfPerimeter3 - side3));


    if (fabs((area0 - (area1 + area2 + area3))) < EPSILON) {
        printf("The point is inside the triangle!\n");
    } else {
        printf("The point is outside the triangle!\n");
    }


    return 0;
}
