#include <stdio.h>



int main() {
    int number1 = 0;
    int number2 = 0;
    int number3 = 0;

    printf("Enter the Number 1: "); if (scanf("%d", &number1) != 1) { puts("Invalid Input!");   return 1;   }
    printf("Enter the Number 2: "); if (scanf("%d", &number2) != 1) { puts("Invalid Input!");   return 1;   }
    printf("Enter the Number 3: "); if (scanf("%d", &number3) != 1) { puts("Invalid Input!");   return 1;   }


    int minNumber2 = (number1 <= number2) ? number1 : number2;
    int maxNumber2 = (number1 >= number2) ? number1 : number2;

    int minNumber3 = (number1 <= number2) ? ((number1 <= number3) ? number1 : number3) : ((number2 <= number3) ? number2 : number3);
    int maxNumber3 = (number1 >= number2) ? ((number1 >= number3) ? number1 : number3) : ((number2 >= number3) ? number2 : number3);


    printf("MIN(%d, %d) is: %d\n",  number1, number2, minNumber2);
    printf("MAX(%d, %d) is: %d\n",  number1, number2, maxNumber2);

    printf("MIN(%d, %d, %d) is: %d\n",  number1, number2, number3, minNumber3);
    printf("MAX(%d, %d, %d) is: %d\n",  number1, number2, number3, maxNumber3);

    
    return 0;
}
