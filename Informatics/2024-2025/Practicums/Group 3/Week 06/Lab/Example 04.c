#include <stdio.h>

void functionA();
void functionB();
void functionC();

int FLAG = 0;

int main() {
    functionA();

    printf("The FLAG value is: %d\n", FLAG);

    return 0;
}

void functionA() {
    printf("Enter A!\n");

    functionB();

    printf("Exit A!\n");
}

void functionB() {
    printf("Enter B!\n");

    functionC();

    printf("Exit B!\n");
}

void functionC() {
    printf("Enter C!\n");

    FLAG = 1;

    printf("Exit C!\n");
}
