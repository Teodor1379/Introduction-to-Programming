#include <stdio.h>

const unsigned int MAX_LETTERS = 10;

int main() {
    char c = '\0';

    scanf("%c", &c);

    unsigned int p = 0;

    while (c <= 'z' && p <= MAX_LETTERS) {
        printf("%c", c);

        c = c + 1;
        p = p + 1;
    }

    putchar('\n');

    return 0;
}
