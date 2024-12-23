#include <stdio.h>



void numbersIntegers    ();
void numbersFloats      ();
void numbersDoubles     ();
void numbersCharacters  ();



void clearStandardInput();



int main() {
    // Logical Operators

    numbersIntegers     ();
    numbersFloats       ();
    numbersDoubles      ();
    numbersCharacters   ();

    return 0;
}



void numbersIntegers() {
    putchar('\n');
    putchar('\n');
    putchar('\n');


    int number1 = 0;
    int number2 = 0;

    printf("Enter the number 1: "); scanf("%d", &number1);
    printf("Enter the number 2: "); scanf("%d", &number2);


    printf("! Number1: %d\n",   !number1);
    printf("! Number2: %d\n",   !number2);


    printf("Number1 && Number2: %d\n",  number1 && number2);
    printf("Number1 || Number2: %d\n",  number1 || number2);


    putchar('\n');
    putchar('\n');
    putchar('\n');
}

void numbersFloats() {
    putchar('\n');
    putchar('\n');
    putchar('\n');


    float number1   =   0.0;
    float number2   =   0.0;

    printf("Enter the number 1: "); scanf("%f", &number1);
    printf("Enter the number 2: "); scanf("%f", &number2);


    printf("! Number1: %d\n",   !number1);
    printf("! Number2: %d\n",   !number2);


    printf("Number1 && Number2: %d\n",  number1 && number2);
    printf("Number1 || Number2: %d\n",  number1 || number2);


    putchar('\n');
    putchar('\n');
    putchar('\n');
}

void numbersDoubles() {
    putchar('\n');
    putchar('\n');
    putchar('\n');


    double number1  =   0.0;
    double number2  =   0.0;

    printf("Enter the number 1: "); scanf("%lf",    &number1);
    printf("Enter the number 2: "); scanf("%lf",    &number2);


    printf("! Number1: %d\n",   !number1);
    printf("! Number2: %d\n",   !number2);


    printf("Number1 && Number2: %d\n", number1 && number2);
    printf("Number1 || Number2: %d\n", number1 || number2);


    putchar('\n');
    putchar('\n');
    putchar('\n');
}

void numbersCharacters() {
    putchar('\n');
    putchar('\n');
    putchar('\n');


    char number1    =   'T';
    char number2    =   'J';

    clearStandardInput();   printf("Enter the Number 1: "); scanf("%c", &number1);
    clearStandardInput();   printf("Enter the Number 2: "); scanf("%c", &number2);


    printf("! Number1: %c\n",   !number1);
    printf("! Number2: %c\n",   !number2);


    printf("Number1 && Number2: %c\n",  number1 && number2);
    printf("Number1 || Number2: %c\n",  number1 || number2);


    putchar('\n');
    putchar('\n');
    putchar('\n');
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}
