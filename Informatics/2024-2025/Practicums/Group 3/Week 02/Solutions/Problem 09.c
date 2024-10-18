#include <stdio.h>

int main() {
    int number = 0;

    printf("Enter the number: ");
    scanf("%d", &number);

    int digit1 = number % 10;
    int digit2 = (number / 10) % 10;
    int digit3 = (number / 100) % 10;
    int digit4 = number / 1000;

    int sumDigits       = digit1 + digit2 + digit3 + digit4;
    int productDigits   = digit1 * digit2 * digit3 * digit4;

    printf("The sum of the digits is: %d\n", sumDigits);
    printf("The product of the digits is: %d\n", productDigits);

    return 0;
}
