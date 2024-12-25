#include <stdio.h>



int main() {
    unsigned int    size    =   0   ;
    char            symbol  =   '$' ;

    do {
        printf("Enter the size: ");

        if (scanf("%u", &size) != 1) {
            puts("Invalid Input!");

            return 1;
        }
    } while (size == 0);

    getchar();

    printf("Enter the symbol: ");

    if (scanf("%c", &symbol) != 1) {
        puts("Invalid Input!");

        return 1;
    }

    for (unsigned int i = 1; i <= size; ++i) {
        for (unsigned int j = 1; j <= i; ++j) {
            putchar(symbol);
            putchar(' ');
        }

        putchar('\n');
    }

    return 0;
}
