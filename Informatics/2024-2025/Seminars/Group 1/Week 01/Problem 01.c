#include <stdio.h>



int main() {
    int number1 = 0;
    int number2 = 0;

    printf("Enter the Number 1: "); scanf("%d", &number1);
    printf("Enter the Number 2: "); scanf("%d", &number2);


    int product = number1 * number2;

    int minNum  = (
        (number1 >  number2) * number2 +
        (number1 <= number2) * number1
    );

    printf("The product of the numbers is: %d\n", product);
    printf("The min     of the numbers is: %d\n", minNum );


    return 0;
}
