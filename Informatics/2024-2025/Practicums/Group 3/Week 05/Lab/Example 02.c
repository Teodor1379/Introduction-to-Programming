#include <stdio.h>

int main() {
    int number = 0;

    do {
        printf("Enter a positive number: ");
        scanf("%d", &number);
    } while (number <= 0);

    printf("The positive number is: %d\n", number);

    return 0;
}
