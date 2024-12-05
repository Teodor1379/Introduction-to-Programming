#include <math.h>

#include <stdio.h>


void solutionOne    ();
void solutionTwo    ();
void solutionThree  ();


int main() {
    solutionOne     ();
    solutionTwo     ();
    solutionThree   ();

    return 0;
}


void solutionOne() {
    double x1 = 0.0;

    double x2 = 0.0;

    printf("Enter Point 1 coordinates: ");  scanf("%lf", &x1);
    printf("Enter Point 2 coordinates: ");  scanf("%lf", &x2);

    printf("The distance is: %lf\n", fabs(x1 - x2));
}

void solutionTwo() {
    double x1 = 0.0;
    double y1 = 0.0;

    double x2 = 0.0;
    double y2 = 0.0;

    printf("Enter Point 1 coordinates: ");  scanf("%lf %lf", &x1, &y1);
    printf("Enter Point 2 coordinates: ");  scanf("%lf %lf", &x2, &y2);

    printf("The distance is: %lf\n", sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)));
}

void solutionThree() {
    double x1 = 0.0;
    double y1 = 0.0;
    double z1 = 0.0;

    double x2 = 0.0;
    double y2 = 0.0;
    double z2 = 0.0;

    printf("Enter Point 1 coordinates: ");  scanf("%lf %lf %lf", &x1, &y1, &z1);
    printf("Enter Point 2 coordinates: ");  scanf("%lf %lf %lf", &x2, &y2, &z2);

    printf("The distance is: %lf\n", sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2)));
}
