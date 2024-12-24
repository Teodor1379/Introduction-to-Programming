#include <stdio.h>



int main() {
    int age = 0;

    int stoleGirl = 0;

    printf("Enter the age: ");

    if (scanf("%d", &age) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    if (age >= 18) {
        int stoleGirl = 1;

        printf("You can go to the disco club!\n");

        printf("Stolen Girl: %d\n", stoleGirl);
    } else {
        printf("Wait some years...\n");
    }


    return 0;
}



// warning: unused variable 'stoleGirl' [-Wunused-variable]
