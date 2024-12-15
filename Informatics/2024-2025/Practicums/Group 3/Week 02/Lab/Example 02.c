#include <stdio.h>



int main() {
    unsigned int age = 0;

    printf("Enter your age: ");

    scanf("%u", &age);

    printf("Your age is: %u\n", age);

    return 0;
}
