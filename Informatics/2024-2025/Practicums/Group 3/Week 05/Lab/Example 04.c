#include <stdio.h>



int main() {
    unsigned int x = 5;
    unsigned int y = 3;

    do {
        if (!(x % y)) {
            continue;
        }

        x -= 1;
        y += 1;
    } while (x > 0);

    printf("%d\n", y);

    return 0;
}
