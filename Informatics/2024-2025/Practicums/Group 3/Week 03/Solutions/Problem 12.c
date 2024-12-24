#include <stdio.h>



int main() {
    unsigned int number =   0;

    printf("Enter the number: ");

    if (scanf("%u", &number) != 1) {
        puts("Invalid Input!");

        return 1;
    }

    if (number < 100 || number > 999) {
        printf("The number is not with 3 digits!\n");

        return 1;
    }

    
    unsigned int digit1 =   number / 100;
    unsigned int digit2 =   (number / 10) % 10;
    unsigned int digit3 =   number % 10;


    if (digit1 % 2 == 0)    { digit1 %= 3;  }   else    { digit1 %= 2;  }
    if (digit2 % 2 == 0)    { digit2 %= 3;  }   else    { digit2 %= 2;  }
    if (digit3 % 2 == 0)    { digit3 %= 3;  }   else    { digit3 %= 2;  }


    number = digit1 * 100 + digit2 * 10 + digit3 * 1;

    printf("The number after the transformation is: %u\n",  number);


    return 0;
}
