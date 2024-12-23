#include <stdio.h>



int main() {
    int number1 =   0;
    int number2 =   0;
    int number3 =   0;

    printf("Enter the Number 1: "); scanf("%d", &number1);
    printf("Enter the Number 2: "); scanf("%d", &number2);
    printf("Enter the Number 3: "); scanf("%d", &number3);


    int countPositive = (number1 > 0) + (number2 > 0) + (number3 > 0);
    int countNegative = (number1 < 0) + (number2 < 0) + (number3 < 0);

    printf("The count of the positive numbers is: %d\n",    countPositive);
    printf("The count of the negative numbers is: %d\n",    countNegative);


    return 0;
}
