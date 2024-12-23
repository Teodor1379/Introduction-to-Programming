#include <stdio.h>



int main() {
    int x = 0;
    int y = 0;


    printf("Enter the number X: "); scanf("%d", &x);
    printf("Enter the number Y: "); scanf("%d", &y);


    printf("X + Y: %d\n", x + y);
    printf("X - Y: %d\n", x - y);
    printf("X * Y: %d\n", x * y);
    printf("X / Y: %d\n", x / y);

    printf("X %% Y: %d\n", x % y);


    printf("X < Y: %d\n", x < y);
    printf("X > Y: %d\n", x > y);

    printf("X <= Y: %d\n", x <= y);
    printf("X >= Y: %d\n", x >= y);

    printf("X == Y: %d\n", x == y);
    printf("X != Y: %d\n", x != y);

    
    printf("X && Y: %d\n", x && y);
    printf("X || Y: %d\n", x || y);


    return 0;
}
