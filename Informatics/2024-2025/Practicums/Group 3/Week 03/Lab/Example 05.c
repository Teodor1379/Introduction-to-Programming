#include <stdio.h>



int main() {
    int number = 0;

    printf("Enter the number: ");

    if (scanf("%d", &number) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    if (number <= 10) {
        printf("The number is less than 11!\n");
    } else if (number > 10 && number <= 15) {
        printf("The number is bigger than 10 and less than 16!\n");
    } else if (number > 15 && number <= 20) {
        printf("The number is bigger than 15 and less than 21!\n");
    } else {
        printf("The number is bigger than 20!\n");
    }


    return 0;
}
