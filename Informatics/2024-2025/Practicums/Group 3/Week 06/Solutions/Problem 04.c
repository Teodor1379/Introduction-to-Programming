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
    scanf("%lf", &value);

    printf("The absolute value of the number is: %lf\n", absoluteValue(value));

    return 0;
}
