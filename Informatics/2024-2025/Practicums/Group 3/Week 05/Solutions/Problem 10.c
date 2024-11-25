#include <stdio.h>

int main() {
    unsigned int    size    =   0   ;
    char            symbol  =   '$' ;

    do {
        printf("Enter the size: ");

        scanf("%u", &size);
    } while (size == 0);

    getchar();

    printf("Enter the symbol: ");

    scanf("%c", &symbol);

    for (unsigned int i = 1; i <= size; ++i) {
        for (unsigned int j = 1; j <= i; ++j) {
            putchar(symbol);
            putchar(' ');
        }

        putchar('\n');
    }

    return 0;
}
