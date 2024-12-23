#include <stdio.h>



int main() {
    int number1 =   0;
    int number2 =   0;

    printf("Enter the Number 1: "); scanf("%d", &number1);
    printf("Enter the Number 2: "); scanf("%d", &number2);


    int minNumber = (number1 < number2) * number1 + (number1 >= number2) * number2;
    int maxNumber = (number1 > number2) * number1 + (number1 <= number2) * number2;

    printf("The min number is: %d\n",   minNumber);
    printf("The max number is: %d\n",   maxNumber);


    return 0;
}
