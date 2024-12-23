#include <stdio.h>



void numbersIntegers    ();
void numbersFloats      ();
void numbersDoubles     ();
void numbersCharacters  ();



void clearStandardInput();



int main() {
    // Assignment Operators

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


    int number1 =   0;
    int number2 =   0;
    int number3 =   0;

    printf("Enter the Number 1: "); scanf("%d", &number1);
    printf("Enter the Number 2: "); scanf("%d", &number2);
    printf("Enter the Number 3: "); scanf("%d", &number3);


    number1 += number2; printf("The Number1 is: %d\n",  number1);
    number1 -= number2; printf("The Number1 is: %d\n",  number1);
    number1 *= number3; printf("The Number1 is: %d\n",  number1);
    number1 /= number3; printf("The Number1 is: %d\n",  number1);
    number1 %= number3; printf("The Number1 is: %d\n",  number1);


    number1 = number2 = number3;

    printf("The Number1 is: %d\n",  number1);
    printf("The Number2 is: %d\n",  number2);
    printf("The Number3 is: %d\n",  number3);


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
    float number3   =   0.0;

    printf("Enter the Number 1: "); scanf("%f", &number1);
    printf("Enter the Number 2: "); scanf("%f", &number2);
    printf("Enter the Number 3: "); scanf("%f", &number3);


    number1 += number2; printf("The Number1 is: %f\n",  number1);
    number1 -= number2; printf("The Number1 is: %f\n",  number1);
    number1 *= number3; printf("The Number1 is: %f\n",  number1);
    number1 /= number3; printf("The Number1 is: %f\n",  number1);


    number1 = number2 = number3;

    printf("The Number1 is: %f\n",  number1);
    printf("The Number2 is: %f\n",  number2);
    printf("The Number3 is: %f\n",  number3);


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
    double number3  =   0.0;

    printf("Enter the Number 1: "); scanf("%lf",    &number1);
    printf("Enter the Number 2: "); scanf("%lf",    &number2);
    printf("Enter the Number 3: "); scanf("%lf",    &number3);


    number1 += number2; printf("The Number1 is: %lf\n", number1);
    number1 -= number2; printf("The Number1 is: %lf\n", number1);
    number1 *= number3; printf("The Number1 is: %lf\n", number1);
    number1 /= number3; printf("The Number1 is: %lf\n", number1);


    number1 = number2 = number3;

    printf("The Number1 is: %lf\n", number1);
    printf("The Number2 is: %lf\n", number2);
    printf("The Number3 is: %lf\n", number3);


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
    char number3    =   'S';

    clearStandardInput();   printf("Enter the Number 1: "); scanf("%c", &number1);
    clearStandardInput();   printf("Enter the Number 2: "); scanf("%c", &number2);
    clearStandardInput();   printf("Enter the Number 3: "); scanf("%c", &number3);


    number1 += number2; printf("The Number1 is: %c\n",  number1);
    number1 -= number2; printf("The Number1 is: %c\n",  number1);
    number1 *= number3; printf("The Number1 is: %c\n",  number1);
    number1 /= number3; printf("The Number1 is: %c\n",  number1);


    number1 = number2 = number3;

    printf("The Number1 is: %c\n",  number1);
    printf("The Number2 is: %c\n",  number2);
    printf("The Number3 is: %c\n",  number3);


    putchar('\n');
    putchar('\n');
    putchar('\n');
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}
