#include <stddef.h>
#include <stdlib.h>

#include <stdio.h>

int main() {
    int array1[9] = { 1, 2, 3 };
    int array2[]  = { 1, 2, 3 };

    for (size_t i = 0; i < 9; ++i) {
        printf("%d ", array1[i]);
    }

    putchar('\n');

    for (size_t i = 0; i < 3; ++i) {
        printf("%d ", array2[i]);
    }

    putchar('\n');

    return 0;
}
