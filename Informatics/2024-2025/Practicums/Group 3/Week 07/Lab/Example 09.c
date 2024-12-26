#include <stdlib.h>

#include <stdio.h>



#define MAX_CAPACITY 100



void clearStandardInput();



int             readElem();
unsigned int    readSize();



void inputArray(        int array[], unsigned int size);
void printArray(const   int array[], unsigned int size);



int filterFunction1(const int number);
int filterFunction2(const int number);
int filterFunction3(const int number);


int mapFunction1(const int number);
int mapFunction2(const int number);
int mapFunction3(const int number);



void filterFunction(const int array[], unsigned int size, int (*f)(int), int result[]);



void mapFunction(int array[], unsigned int size, int (*f)(int));




int main() {
    int (*filterFunctionPointer1)(const int)    =   &filterFunction1;
    int (*filterFunctionPointer2)(const int)    =   &filterFunction2;
    int (*filterFunctionPointer3)(const int)    =   &filterFunction3;

    int (*mapFunctionPointer1)(const int)   =   &mapFunction1;
    int (*mapFunctionPointer2)(const int)   =   &mapFunction2;
    int (*mapFunctionPointer3)(const int)   =   &mapFunction3;


    int array[MAX_CAPACITY]     =   { 0 };

    int array1[MAX_CAPACITY]    =   { 0 };
    int array2[MAX_CAPACITY]    =   { 0 };
    int array3[MAX_CAPACITY]    =   { 0 };

    int result1[MAX_CAPACITY]   =   { 0 };
    int result2[MAX_CAPACITY]   =   { 0 };
    int result3[MAX_CAPACITY]   =   { 0 };


    unsigned int size = readSize();


    inputArray(array, size);    printArray(array, size);

    filterFunction(array, size, filterFunctionPointer1, result1);   printArray(result1, size);
    filterFunction(array, size, filterFunctionPointer2, result2);   printArray(result2, size);
    filterFunction(array, size, filterFunctionPointer3, result3);   printArray(result3, size);



    inputArray(array1, size);   printArray(array1, size);
    inputArray(array2, size);   printArray(array2, size);
    inputArray(array3, size);   printArray(array3, size);

    mapFunction(array1, size, mapFunctionPointer1); printArray(array1, size);
    mapFunction(array2, size, mapFunctionPointer2); printArray(array2, size);
    mapFunction(array3, size, mapFunctionPointer3); printArray(array3, size);


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



int readElem() {
    int elem            =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%d", &elem);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return elem;
}

unsigned int readSize() {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the size of the array: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX_CAPACITY);

    return size;
}



int filterFunction1(const int number)   {   return number >= 0; }
int filterFunction2(const int number)   {   return number <= 0; }
int filterFunction3(const int number)   {   return number == 0; }



int mapFunction1(const int number)  { return number > 0 ? number : 0;   }
int mapFunction2(const int number)  { return number < 0 ? number : 0;   }
int mapFunction3(const int number)  { return number * number * number;  }



void inputArray(int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const int array[], unsigned int size) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}



void filterFunction(const int array[], unsigned int size, int (*f)(int), int result[]) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    unsigned int counter = 0;

    for (unsigned int i = 0; i < size; ++i) {
        if (f(array[i])) {
            result[counter] = array[i];

            counter = counter + 1;
        }
    }
}



void mapFunction(int array[], unsigned int size, int (*f)(int)) {
    if (size == 0 || size > MAX_CAPACITY) {
        printf("Invalid size for the array!\n");

        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = f(array[i]);
    }
}
