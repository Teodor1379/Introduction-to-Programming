#include <stdio.h>



double absoluteValue(double value) {
    if (value < 0) {
        return -value;
    }

    return value;
}



int main() {
    double value = 0.0;

    printf("Enter the value: ");

    if (scanf("%lf", &value) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    printf("The absolute value of the number is: %lf\n", absoluteValue(value));


    return 0;
}
