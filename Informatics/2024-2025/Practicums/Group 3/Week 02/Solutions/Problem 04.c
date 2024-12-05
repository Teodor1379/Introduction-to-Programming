#include <stdio.h>


int main() {
    int x = 0;
    int y = 0;

    printf("Enter x: ");    scanf("%d", &x);
    printf("Enter y: ");    scanf("%d", &y);

    printf("x + y: %d\n", x + y);
    printf("x - y: %d\n", x - y);
    printf("x * y: %d\n", x * y);
    printf("x / y: %d\n", x / y);
    printf("x %% y: %d\n", x % y);

    printf("x < y: %d\n", x < y);
    printf("x > y: %d\n", x > y);
    printf("x <= y: %d\n", x <= y);
    printf("x >= y: %d\n", x >= y);
    printf("x == y: %d\n", x == y);
    printf("x != y: %d\n", x != y);

    return 0;
}
