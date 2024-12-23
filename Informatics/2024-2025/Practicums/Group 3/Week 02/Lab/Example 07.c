#include <stdio.h>



void numbersIntegers    ();
void numbersFloats      ();
void numbersDoubles     ();
void numbersCharacters  ();



void clearStandardInput();



int main() {
    // Arithmetic Operators
    
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


    printf("+ Number1: %d\n", +number1);    // Unary Plus
    printf("+ Number2: %d\n", +number2);    // Unary Plus

    printf("- Number1: %d\n", -number1);    // Unary Minus
    printf("- Number2: %d\n", -number2);    // Unary Minus


    printf("Number1 + Number2: %d\n", number1 + number2);   // Addition
    printf("Number1 - Number2: %d\n", number1 - number2);   // Subtraction
    printf("Number1 * Number2: %d\n", number1 * number2);   // Multiplication
    printf("Number1 / Number2: %d\n", number1 / number2);   // Division

    printf("Number1 %% Number2: %d\n", number1 % number2);  // Modulo


    printf("++ Number1: %d\n", ++number1);  // Increment (Prefix)
    printf("++ Number2: %d\n", ++number2);  // Increment (Prefix)

    printf("-- Number1: %d\n", --number1);  // Decrement (Prefix)
    printf("-- Number2: %d\n", --number2);  // Decrement (Prefix)


    printf("Number1 ++: %d\n", number1++);  // Increment (Postfix)
    printf("Number2 ++: %d\n", number2++);  // Increment (Postfix)

    printf("Number1: %d\n", number1);
    printf("Number2: %d\n", number2);

    printf("Number1 --: %d\n", number1--);  // Decrement (Postfix)
    printf("Number1 --: %d\n", number2--);  // Decrement (Postfix)

    printf("Number1: %d\n", number1);
    printf("Number2: %d\n", number2);


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


    printf("+ Number1: %f\n", +number1);    // Unary Plus
    printf("+ Number2: %f\n", +number2);    // Unary Plus

    printf("- Number1: %f\n", -number1);    // Unary Minus
    printf("- Number2: %f\n", -number2);    // Unary Minus


    printf("Number1 + Number2: %f\n", number1 + number2);   // Addition
    printf("Number1 - Number2: %f\n", number1 - number2);   // Subtraction
    printf("Number1 * Number2: %f\n", number1 * number2);   // Multiplication
    printf("Number1 / Number2: %f\n", number1 / number2);   // Division
    
    
    printf("++ Number1: %f\n",  ++number1); // Increment (Prefix)
    printf("++ Number2: %f\n",  ++number2); // Increment (Prefix)

    printf("-- Number1: %f\n",  --number1); // Decrement (Prefix)
    printf("-- Number2: %f\n",  --number2); // Decrement (Prefix)

    
    printf("Number1 ++: %f\n",  number1++); // Increment (Postfix)
    printf("Number2 ++: %f\n",  number2++); // Increment (Postfix)

    printf("Number1: %f\n", number1);
    printf("Number2: %f\n", number2);

    printf("Number1 --: %f\n", number1--);  // Decrement (Postfix)
    printf("Number2 --: %f\n", number2--);  // Decrement (Postfix)

    printf("Number1: %f\n", number1);
    printf("NUmber2: %f\n", number2);


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


    printf("+ Number1: %lf\n",  +number1);  // Unary Plus
    printf("+ Number2: %lf\n",  +number2);  // Unary Plus

    printf("- Number1: %lf\n",  -number1);  // Unary Minus
    printf("- Number2: %lf\n",  -number2);  // Unary Minus


    printf("Number1 + Number2: %lf\n",  number1 + number2); // Addition
    printf("Number1 - Number2: %lf\n",  number1 - number2); // Subtraction
    printf("Number1 * Number2: %lf\n",  number1 * number2); // Multiplication
    printf("Number1 / Number2: %lf\n",  number1 / number2); // Division

    printf("++ Number1: %lf\n", ++number1); // Increment (Prefix)
    printf("++ Number2: %lf\n", ++number2); // Increment (Prefix)

    printf("-- Number1: %lf\n", --number1); // Decrement (Prefix)
    printf("-- Number2: %lf\n", --number2); // Decrement (Prefix)


    printf("Number1 ++: %lf\n", number1++); // Increment (Postfix)
    printf("Number2 ++: %lf\n", number2++); // Increment (Postfix)

    printf("Number1: %lf\n",    number1);
    printf("Number2: %lf\n",    number2);

    printf("Number1 --: %lf\n", number1--); // Decrement (Postfix)
    printf("Number2 --: %lf\n", number2--); // Decrement (Postfix)

    printf("Number1: %lf\n",    number1);
    printf("Number2: %lf\n",    number2);


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


    printf("+ Number1: %c\n", +number1);    // Unary Plus
    printf("+ Number2: %c\n", +number2);    // Unary Plus

    printf("- Number1: %c\n", -number1);    // Unary Minus
    printf("- Number2: %c\n", -number2);    // Unary Minus


    printf("Number1 + Number2: %c\n",   number1 + number2); // Addition
    printf("Number1 - Number2: %c\n",   number1 - number2); // Subtraction
    printf("Number1 * Number2: %c\n",   number1 * number2); // Multiplication
    printf("Number1 / Number2: %c\n",   number1 / number2); // Division

    printf("Number1 %% Number2: %c\n",  number1 % number2); // Modulo


    printf("++ Number1: %c\n",  ++number1); // Increment (Prefix)
    printf("++ Number2: %c\n",  ++number2); // Increment (Prefix)

    printf("-- Number1: %c\n",  --number1); // Decrement (Prefix)
    printf("-- Number2: %c\n",  --number2); // Decrement (Prefix)


    printf("Number1 ++: %c\n",  number1++); // Increment (Postfix)
    printf("Number2 ++: %c\n",  number2++); // Increment (Postfix)

    printf("Number1: %c\n", number1);
    printf("Number2: %c\n", number2);

    printf("Number1 --: %c\n",  number1--); // Decrement (Postfix)
    printf("Number2 --: %c\n",  number2--); // Decrement (Postfix)

    printf("Number1: %c\n", number1);
    printf("Number2: %c\n", number2);


    putchar('\n');
    putchar('\n');
    putchar('\n');
}
