#include <stdio.h>



int main() {
    int array1[9] = { 1, 2, 3 };
    int array2[]  = { 1, 2, 3 };


    unsigned int size1 = sizeof(array1) / sizeof(int);
    unsigned int size2 = sizeof(array2) / sizeof(int);


    printf("The start element of the array 1 is: %d\n", array1[        0]);
    printf("The final element of the array 1 is: %d\n", array1[size1 - 1]);

    printf("The start element of the array 2 is: %d\n", array2[        0]);
    printf("The final element of the array 2 is: %d\n", array2[size2 - 1]);

    printf("Invalid Value 1 is: %d\n",  array1[   -1]);
    printf("Invalid Value 2 is: %d\n",  array2[size2]);


    for (unsigned int i = 0; i < 9; ++i) {
        printf("%d ", array1[i]);
    }

    putchar('\n');

    for (unsigned int i = 0; i < 3; ++i) {
        printf("%d ", array2[i]);
    }

    putchar('\n');


    return 0;
}
