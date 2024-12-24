#include <stdio.h>



int main() {
    int a   =   0;
    int b   =   0;
    int x   =   0;

    printf("Enter the number a: "); if (scanf("%d", &a) != 1)   { puts("Invalid Input!");   return 1;   }
    printf("Enter the number b: "); if (scanf("%d", &b) != 1)   { puts("Invalid Input!");   return 1;   }
    printf("Enter the number x: "); if (scanf("%d", &x) != 1)   { puts("Invalid Input!");   return 1;   }


    if (a > b) {
        printf("The given interval is invalid!\n");
    } else {
        if (x < a) {
            printf("Smaller than a!\n");
        } else if (x >= a && x <= b) {
            printf("In the interval!\n");
        } else {
            printf("Bigger than b!\n");
        }
    }


    return 0;
}
