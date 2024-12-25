#include <stdio.h>



int factorial(int number);



int main() {
    printf("The factorial of 1 is: %d\n",   factorial(1));
    printf("The factorial of 3 is: %d\n",   factorial(3));
    printf("The factorial of 3 is: %d\n",   factorial(3));
    printf("The factorial of 9 is: %d\n",   factorial(9));

    return 0;
}



int factorial(int number) {
    int result = 1;

    for (int i = 1; i <= number; ++i) {
        result = result * i;
    }

    return result;
}
