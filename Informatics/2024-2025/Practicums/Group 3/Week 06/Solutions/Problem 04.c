#include <stdio.h>



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



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

        clearStandardInput();
    }


    printf("The absolute value of the number is: %lf\n", absoluteValue(value));


    return 0;
}
