#include <stdio.h>



int main() {
    // With third variable:

    int a = 1;
    int b = 3;

    int c = 0;

    c = a;
    a = b;
    b = c;

    printf("a is: %d\n", a);
    printf("b is: %d\n", b);

    // Without third variable:

    int x = 7;
    int y = 9;

    x = x + y;
    y = x - y;
    x = x - y;

    printf("x is: %d\n", x);
    printf("y is: %d\n", y);

    return 0;
}
