#include <assert.h>

#include <stdlib.h>

#include <stdio.h>



#define MAX 32



void clearStandardInput();



unsigned int*   buildArray(                     );
void            clearArray(unsigned int** array );

void            printArray(unsigned int* array  );



void convertBinary(unsigned int number);



int main() {
    unsigned int number =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the decimal number: ");

        inputArgument = scanf("%u", &number);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);


    convertBinary(number);


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int* buildArray() {
    unsigned int* array = (unsigned int*)(malloc(MAX * sizeof(unsigned int)));

    if (array != NULL) {
        for (unsigned int i = 0; i < MAX; ++i) {
            array[i] = 0;
        }
    }

    return array;
}

void clearArray(unsigned int** array) {
    assert(*array != NULL);

    free(*array);

    *array = NULL;
}


void printArray(unsigned int* array) {
    printf("The bit representation is: ");

    for (unsigned int i = 0; i < MAX; ++i) {
        printf("%u", array[i]);
    }

    putchar('\n');
}



void convertBinary(unsigned int number) {
    unsigned int* array = buildArray();

    if (array == NULL) {
        puts("Allocating Memory... ERROR!");

        return;
    }

    unsigned int index = MAX - 1;

    while (number > 0) {
        array[index] = number % 2;

        number  =   number  /   2;
        index   =   index   -   1;
    }

    printArray(array);

    clearArray(&array);
}
