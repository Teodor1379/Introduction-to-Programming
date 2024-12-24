#include <stdio.h>



void numbersIntegers    ();
void numbersCharacters  ();



void clearStandardInput();



int main() {
    // Assignment Operatos

    numbersIntegers     ();
    numbersCharacters   ();

    return 0;
}



void numbersIntegers() {
    putchar('\n');
    putchar('\n');
    putchar('\n');


    int number1 =   0;
    int number2 =   0;

    printf("Enter the Number 1: "); scanf("%d", &number1);
    printf("Enter the Number 2: "); scanf("%d", &number2);


    number1 &= number2; printf("Number1 is: %d\n",  number1);
    number1 |= number2; printf("Number1 is: %d\n",  number1);
    number1 ^= number2; printf("Number1 is: %d\n",  number1);

    number1 <<= 0;  printf("Number1 is: %d\n",  number1);
    number1 <<= 1;  printf("Number1 is: %d\n",  number1);

    number2 >>= 0;  printf("Number2 is: %d\n",  number2);
    number2 >>= 1;  printf("Number2 is: %d\n",  number2);


    putchar('\n');
    putchar('\n');
    putchar('\n');
}

void numbersCharacters() {
    putchar('\n');
    putchar('\n');
    putchar('\n');


    char number1    =   0;
    char number2    =   0;

    clearStandardInput();   printf("Enter the Number 1: "); scanf("%c", &number1);
    clearStandardInput();   printf("Enter the Number 2: "); scanf("%c", &number2);


    number1 &= number2; printf("Number1 is: %c\n",  number1);
    number1 |= number2; printf("Number1 is: %c\n",  number1);
    number1 ^= number2; printf("Number1 is: %c\n",  number1);

    number1 <<= 0;  printf("Number1 is: %c\n",  number1);
    number1 <<= 1;  printf("Number1 is: %c\n",  number1);

    number2 >>= 0;  printf("Number2 is: %c\n",  number2);
    number2 >>= 1;  printf("Number2 is: %c\n",  number2);


    putchar('\n');
    putchar('\n');
    putchar('\n');
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}
