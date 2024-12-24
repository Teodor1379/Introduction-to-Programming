#include <stdio.h>



int main() {
    int age = 0;

    printf("Enter your age: ");

    if (scanf("%d", &age) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    if (age >= 18) {
        puts("You can go to the disco club!");
    }

    
    return 0;
}
