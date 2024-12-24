#include <stdio.h>



void numbersIntegers    ();
void numbersCharacters  ();



void clearStandardInput();



int main() {
    // Bitwise Operators

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


    printf("~ Number1 is: %d\n",    ~number1);
    printf("~ Number2 is: %d\n",    ~number2);

    printf("Number1 & Number2 is: %d\n",    number1 & number2);
    printf("Number1 | Number2 is: %d\n",    number1 | number2);
    printf("Number1 ^ Number2 is: %d\n",    number1 ^ number2);

    printf("Number1 Bit 1 is: %d\n",    number1 << 0);
    printf("Number1 Bit 2 is: %d\n",    number1 << 1);
    printf("Number1 Bit 3 is: %d\n",    number1 << 2);
    printf("Number1 Bit 4 is: %d\n",    number1 << 3);
    printf("Number1 Bit 5 is: %d\n",    number1 << 4);
    printf("Number1 Bit 6 is: %d\n",    number1 << 5);
    printf("Number1 Bit 7 is: %d\n",    number1 << 6);
    printf("Number1 Bit 8 is: %d\n",    number1 << 8);

    printf("Number2 Bit 8 is: %d\n",    number2 >> 0);
    printf("Number2 Bit 7 is: %d\n",    number2 >> 1);
    printf("Number2 Bit 6 is: %d\n",    number2 >> 2);
    printf("Number2 Bit 5 is: %d\n",    number2 >> 3);
    printf("Number2 Bit 4 is: %d\n",    number2 >> 4);
    printf("Number2 Bit 3 is: %d\n",    number2 >> 5);
    printf("Number2 Bit 2 is: %d\n",    number2 >> 6);
    printf("Number2 Bit 1 is: %d\n",    number2 >> 7);


    putchar('\n');
    putchar('\n');
    putchar('\n');
}

void numbersCharacters() {
    putchar('\n');
    putchar('\n');
    putchar('\n');


    char number1    =   'J';
    char number2    =   'T';

    clearStandardInput();   printf("Enter the Number 1: "); scanf("%c", &number1);
    clearStandardInput();   printf("Enter the Number 2: "); scanf("%c", &number2);


    printf("~ Number1 is: %c\n",    ~number1);
    printf("~ Number2 is: %c\n",    ~number2);

    printf("Number1 & Number2 is: %c\n",    number1 & number2);
    printf("Number1 | Number2 is: %c\n",    number1 | number2);
    printf("Number1 ^ Number2 is: %c\n",    number1 ^ number2);

    printf("Number1 Bit 1 is: %c\n",    number1 << 0);
    printf("Number1 Bit 2 is: %c\n",    number1 << 1);
    printf("Number1 Bit 3 is: %c\n",    number1 << 2);
    printf("Number1 Bit 4 is: %c\n",    number1 << 3);
    printf("Number1 Bit 5 is: %c\n",    number1 << 4);
    printf("Number1 Bit 6 is: %c\n",    number1 << 5);
    printf("Number1 Bit 7 is: %c\n",    number1 << 6);
    printf("Number1 Bit 8 is: %c\n",    number1 << 7);

    printf("Number2 Bit 8 is: %c\n",    number2 >> 0);
    printf("Number2 Bit 7 is: %c\n",    number2 >> 1);
    printf("Number2 Bit 6 is: %c\n",    number2 >> 2);
    printf("Number2 Bit 5 is: %c\n",    number2 >> 3);
    printf("Number2 Bit 4 is: %c\n",    number2 >> 4);
    printf("Number2 Bit 3 is: %c\n",    number2 >> 5);
    printf("Number2 Bit 2 is: %c\n",    number2 >> 6);
    printf("Number2 Bit 1 is: %c\n",    number2 >> 7);


    putchar('\n');
    putchar('\n');
    putchar('\n');
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}
