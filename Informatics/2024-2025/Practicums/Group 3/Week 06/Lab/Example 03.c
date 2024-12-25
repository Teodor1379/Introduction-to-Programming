#include <stdio.h>



void swap(int a, int b) {
    int c = 0;

    c = a;
    a = b;
    b = c;
}



int main() {
    int x   =   0;
    int y   =   0;

    printf("Enter the number X: "); if (scanf("%d", &x) != 1)   { puts("Invalid Input!");   return 1;   }
    printf("Enter the number Y: "); if (scanf("%d", &y) != 1)   { puts("Invalid Input!");   return 1;   }

    swap(x, y);

    printf("The result number X is: %d\n", x);
    printf("The result number Y is: %d\n", y);

    return 0;
}
