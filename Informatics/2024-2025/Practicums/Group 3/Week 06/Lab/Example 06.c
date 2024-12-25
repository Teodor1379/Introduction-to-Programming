#include <stdio.h>



void clearStandardInput();



int main() {
    int number = 0;

    do {
        printf("Enter an integer: ");

        if (scanf("%d", &number) != 1) {
            clearStandardInput();
        }
    } while (number <= 0);


    printf("The integer is: %d\n", number);


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}
