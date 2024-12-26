#include <stdio.h>



#define PI_M    3.14        // Macro



const double PI_V = 3.14;   // Variable



void swapFake(int  a, int  b);
void swapReal(int* a, int* b);



void samples();



int main() {
    int x   =   0;
    int y   =   0;

    printf("Enter the number X: "); if (scanf("%d", &x) != 1)   { puts("Invalid Input!");   return 1;   }
    printf("Enter the number Y: "); if (scanf("%d", &y) != 1)   { puts("Invalid Input!");   return 1;   }


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

    printf("The value of pointer 1 is: %p\n", (void*)(p1));
    printf("The value of pointer 2 is: %p\n", (void*)(p2));

    printf("Referencing pointer 1 is: %d\n", *p1);
    printf("Referencing pointer 2 is: %d\n", *p2);

    const int e = 0;    // Constant Variable or Constant
    int const f = 1;    // Constant Variable or Constant

    printf("The variable E is: %d\n",   e);
    printf("The variable F is: %d\n",   f);

    const int* pointer1 = &a;   pointer1 = &b; // *pointer1 = 10;   (Impossible)
    int* const pointer2 = &b;   *pointer2 = 1; // pointer2 = &a;    (Impossible)

    const int* const pointer3 = &c;

    // pointer3     = &b; (Impossible)
    // *pointer3    = 10; (Impossible)

    printf("Referencing pointer 1 is: %d\n",    *pointer1);
    printf("Referencing pointer 2 is: %d\n",    *pointer2);
    printf("Referencing pointer 3 is: %d\n",    *pointer3);
}
