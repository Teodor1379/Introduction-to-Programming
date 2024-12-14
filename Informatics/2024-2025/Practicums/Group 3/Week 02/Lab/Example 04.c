#include <stdio.h>


int main() {
    float C =   0.0;
    float F =   0.0;

    printf("Enter the Celsium degrees: ");

    scanf("%f", &C);

    F = C * 1.8 + 32;

    printf("The Fahrenheit degrees are: %f\n", F);

    return 0;
}
