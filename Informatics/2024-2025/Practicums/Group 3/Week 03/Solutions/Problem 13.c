#include <math.h>

#include <stdio.h>



#define EPSILON 1e-9



int main() {
    char operation  =   'T';

    printf("Enter the operation O: ");

    if (scanf("%c", &operation) != 1) {
        puts("Invalid Input!");

        return 1;
    }


    double number1  =   0.0;
    double number2  =   0.0;

    printf("Enter the number X: "); if (scanf("%lf",    &number1) != 1) { puts("Invalid Input!");   return 1;   }
    printf("Enter the number Y: "); if (scanf("%lf",    &number2) != 1) { puts("Invalid Input!");   return 1;   }


    double result   =   0.0;

    switch (operation) {
        case '+':   result = number1 + number2;     break;
        case '-':   result = number1 - number2;     break;
        case '*':   result = number1 * number2;     break;
        case '/':
            if (fabs(number2) < EPSILON) {
                puts("Division by Zero!");

                return 1;
            }

                    result = number1 / number2;     break;
        case '^':   result = pow(number1, number2); break;
        default:    puts("Invalid Operation!");
    }

    printf("The result is: %lf\n", result);


    return 0;
}
