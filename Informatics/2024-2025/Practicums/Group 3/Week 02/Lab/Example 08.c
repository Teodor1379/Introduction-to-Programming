#include <math.h>

#include <stdio.h>



#define EPSILON 1e-9;



void numbersIntegers    ();
void numbersFloats      ();
void numbersDoubles     ();
void numbersCharacters  ();



void clearStandardInput();



int main() {
    // Relational Operators

    numbersIntegers     ();
    numbersFloats       ();
    numbersDoubles      ();
    numbersCharacters   ();

    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



void numbersIntegers() {
    putchar('\n');
    putchar('\n');
    putchar('\n');


    int number1 =   0;
    int number2 =   0;

    printf("Enter the Number 1: "); scanf("%d", &number1);
    printf("Enter the Number 2: "); scanf("%d", &number2);


    printf("Number1 < Number2: %d\n",   number1 < number2);     // Less     Than
    printf("Number1 > Number2: %d\n",   number1 > number2);     // Greather Than

    printf("Number1 <= Number2: %d\n",  number1 <= number2);    // Less     Than or Equal
    printf("Number1 >= Number2: %d\n",  number1 >= number2);    // Greater  Than or Equal

    printf("Number1 == Number2: %d\n",  number1 == number2);    //      Equal
    printf("Number1 != Number2: %d\n",  number1 != number2);    // Not  Equal


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

    printf("Enter the Number 1: "); scanf("%f", &number1);
    printf("Enter the Number 2: "); scanf("%f", &number2);


    printf("Number1 < Number2: %d\n",   number1 < number2);             // Less     Than
    printf("Number1 > Number2: %d\n",   number1 > number2);             // Greater  Than

    printf("Number1 <= Number2: %d\n",  number1 <= number2);            // Less     Than or Equal
    printf("Number1 >= Number2: %d\n",  number1 >= number2);            // Greater  Than or Equal

    printf("Number1 == Number2: %d\n",  fabs(number1 - number2) <  0);  //      Equal
    printf("Number1 != Number2: %d\n",  fabs(number1 - number2) >= 0);  // Not  Equal


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

    printf("Enter the Number 1: "); scanf("%lf",    &number1);
    printf("Enter the Number 2: "); scanf("%lf",    &number2);


    printf("Number1 < Number2: %d\n",   number1 < number2);             // Less     Than
    printf("Number1 > Number2: %d\n",   number1 > number2);             // Greater  Than

    printf("Number1 <= Number2: %d\n",  number1 <= number2);            // Less     Than or Equal
    printf("Number1 >= Number2: %d\n",  number1 >= number2);            // Greater  Than or Equal

    printf("Number1 == Number2: %d\n",  fabs(number1 - number2) <  0);  //      Equal
    printf("Number1 != Number2: %d\n",  fabs(number1 - number2) >= 0);  // Not  Equal


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


    printf("Number1 < Number2: %d\n",   number1 < number2);     // Less     Than
    printf("Number1 > Number2: %d\n",   number1 > number2);     // Greater  Than

    printf("Number1 <= Number2: %d\n",  number1 <= number2);    // Less     Than or Equal
    printf("Number1 >= Number2: %d\n",  number1 >= number2);    // Greater  Than or Equal

    printf("Number1 == Number2: %d\n",  number1 == number2);    //      Equal
    printf("Number1 != Number2: %d\n",  number1 != number2);    // Not  Equal


    putchar('\n');
    putchar('\n');
    putchar('\n');
}
