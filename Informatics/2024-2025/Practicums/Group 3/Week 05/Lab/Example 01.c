#include <stdio.h>



const unsigned int MAX_LETTERS = 10;



int main() {
    char c = '\0';

    if (scanf("%c", &c) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    unsigned int p = 0;

    while (c <= 'z' && p <= MAX_LETTERS) {
        printf("%c", c);

        c = c + 1;
        p = p + 1;
    }

    putchar('\n');


    return 0;
}
