#include <stdio.h>



int min2(int number1, int number2);
int min3(int number1, int number2, int number3);

int max2(int number1, int number2);
int max3(int number1, int number2, int number3);



int main() {
    printf("The min of 2 arguments is: %d\n",   min2(1, 3)      );
    printf("The min of 3 arguments is: %d\n",   min3(1, 3, 7)   );

    printf("The max of 2 arguments is: %d\n",   max2(1, 3)      );
    printf("The max of 3 arguments is: %d\n",   max3(1, 3, 7)   );


    return 0;
}



int min2(int number1, int number2)              {   return number1 < number2 ? number1 : number2;   }
int min3(int number1, int number2, int number3) {   return min2(number1, min2(number2, number3));   }

int max2(int number1, int number2)              {   return number1 > number2 ? number1 : number2;   }
int max3(int number1, int number2, int number3) {   return max2(number1, max2(number2, number3));   }
