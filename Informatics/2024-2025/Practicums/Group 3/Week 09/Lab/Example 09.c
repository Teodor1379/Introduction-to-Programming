#include <stdio.h>


void swapFake(int  a, int  b);
void swapReal(int* a, int* b);


void samples();


int main() {
    int x   =   0;
    int y   =   0;

    printf("Enter the number X: "); scanf("%d", &x);
    printf("Enter the number Y: "); scanf("%d", &y);

    swapFake(x, y);

    printf("The number X after swap FAKE is: %d\n", x);
    printf("The number Y after swap FAKE is: %d\n", y);

    swapReal(&x, &y);

    printf("The number X after swap REAL is: %d\n", x);
    printf("The number Y after swap REAL is: %d\n", y);

    samples();

    return 0;
}


void swapFake(int  a, int  b) {
    int c = 0;

    c   =   a;
    a   =   b;
    b   =   c;
}

void swapReal(int* a, int* b) {
    int c = 0;

     c  =   *a;
    *a  =   *b;
    *b  =    c;
}


void samples() {
    int a = 3;
    int b = 9;
    int c = 7;

    int* p1 = &a;
    int* p2 = &b;

    printf("The value of pointer 1 is: %p\n", p1);
    printf("The value of pointer 2 is: %p\n", p2);

    printf("Referencing pointer 1 is: %d\n", *p1);
    printf("Referencing pointer 2 is: %d\n", *p2);

    const int* pointer1 = &a;   // pointer1 = &b;
    int* const pointer2 = &b;   // *pointer2 = 1;

    const int* const pointer3 = &c;
}
