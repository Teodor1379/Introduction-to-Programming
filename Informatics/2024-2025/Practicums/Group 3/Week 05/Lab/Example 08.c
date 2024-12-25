#include <stdio.h>



#define BOUND 65536



int main() {
    for (unsigned int i = 1; i <= BOUND; i *= 2) {
        printf("%u ", i);
    }

    putchar('\n');


    return 0;
}
