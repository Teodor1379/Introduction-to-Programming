#include <stdio.h>



#define MILES_INTO_KILOMETERS 1.609344



int main() {
    float velocityMPH   =   0.0;
    float velocityKMPH  =   0.0;


    printf("Enter the Velocity in Miles per Hour: ");

    scanf("%f", &velocityMPH);


    velocityKMPH = velocityMPH * MILES_INTO_KILOMETERS;

    printf("The Velocity in Kilometers per Hour is: %f\n", velocityKMPH);


    return 0;
}
