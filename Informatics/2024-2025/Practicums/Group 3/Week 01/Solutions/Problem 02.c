#include <stdio.h>


int main() {
    int number = 0;

    printf("Enter the number: ");

    scanf("%d", &number);

    number = number + 1;

    printf("The SUCC result is: %d\n", number);

    return 0;
}
