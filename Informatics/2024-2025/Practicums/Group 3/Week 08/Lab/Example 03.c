#include <stdio.h>



static int number = 0;



void function() {
    static  int current1    =   0;
            int current2    =   0;

    current1    =   current1 + 10;
    current2    =   current2 + 10;

    printf("Current 1 is: %d\n", current1);
    printf("Current 2 is: %d\n", current2);

    putchar('\n');
}



int main() {
    printf("The number variable is: %d\n\n\n", number);

    function();
    function();
    function();

    return 0;
}
