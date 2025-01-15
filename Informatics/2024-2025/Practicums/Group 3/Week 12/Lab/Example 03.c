#include <assert.h>

#include <limits.h>

#include <stdio.h>



#define MAX 100



void clearStandardInput();



unsigned int    readElem();
unsigned int    readNumb();
unsigned int    readSize();



unsigned int minFunction(unsigned int number1, unsigned int number2);
unsigned int maxFunction(unsigned int number1, unsigned int number2);



unsigned int findGCD1(unsigned int number1, unsigned int number2);
unsigned int findGCD2(unsigned int number1, unsigned int number2);
unsigned int findGCD3(unsigned int number1, unsigned int number2);



void inputArray(        unsigned int array[MAX], unsigned int size);
void printArray(const   unsigned int array[MAX], unsigned int size);



void findMinNumberArray(const unsigned int array[MAX], unsigned int size, unsigned int i, unsigned int* result);
void findMaxNumberArray(const unsigned int array[MAX], unsigned int size, unsigned int i, unsigned int* result);



int main() {
    unsigned int number1 = readNumb();
    unsigned int number2 = readNumb();

    unsigned int result1 = findGCD1(number1, number2);
    unsigned int result2 = findGCD2(number1, number2);
    unsigned int result3 = findGCD3(number1, number2);

    printf("The GCD 1 Result is: %u\n", result1);
    printf("The GCD 2 Result is: %u\n", result2);
    printf("The GCD 3 Result is: %u\n", result3);


    unsigned int array[MAX] = { 0 };

    unsigned int size = readSize();

    inputArray(array, size);
    printArray(array, size);

    unsigned int minNumber = UINT_MAX   ;
    unsigned int maxNumber = 0          ;

    findMinNumberArray(array, size, 0, &minNumber);
    findMaxNumberArray(array, size, 0, &maxNumber);

    printf("The MIN number in the array is: %d\n",  minNumber);
    printf("The MAX number in the array is: %d\n",  maxNumber);


    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readElem() {
    unsigned int elem   =   0;
    int inputArgument   =   0;

    do {
        inputArgument = scanf("%u", &elem);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return elem;
}

unsigned int readNumb() {
    unsigned int numb   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the number: ");

        inputArgument = scanf("%u", &numb);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1);

    return numb;
}

unsigned int readSize() {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the size: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX);

    return size;
}



unsigned int minFunction(unsigned int number1, unsigned int number2) {
    return number1 <= number2 ? number1 : number2;
}

unsigned int maxFunction(unsigned int number1, unsigned int number2) {
    return number1 >= number2 ? number1 : number2;
}



unsigned int findGCD1(unsigned int number1, unsigned int number2) {
    if (number1 == number2) {
        return number1;
    }

    if (number1 > number2) {
        return findGCD1(number1 - number2, number2);
    } else {
        return findGCD1(number1, number2 - number1);
    }
}

unsigned int findGCD2(unsigned int number1, unsigned int number2) {
    if (number1 == 0) {
        return number2;
    }

    if (number2 == 0) {
        return number1;
    }

    if (number1 > number2) {
        return findGCD2(number1 - number2, number2);
    } else {
        return findGCD2(number1, number2 - number1);
    }
}

unsigned int findGCD3(unsigned int number1, unsigned int number2) {
    if (number1 == 0) {
        return number2;
    }

    if (number2 == 0) {
        return number1;
    }

    unsigned int minNumber = minFunction(number1, number2);
    unsigned int maxNumber = maxFunction(number1, number2);

    printf("The current numbers are: %u %u\n", minNumber, maxNumber);

    return findGCD3(minNumber, maxNumber % minNumber);
}



void inputArray(unsigned int array[MAX], unsigned int size) {
    assert(size > 0     );
    assert(size <= MAX  );

    printf("Enter the elements of the array: ");

    for (unsigned int i = 0; i < size; ++i) {
        array[i] = readElem();
    }
}

void printArray(const unsigned int array[MAX], unsigned int size) {
    assert(size > 0     );
    assert(size <= MAX  );

    printf("The elements of the array are: ");

    for (unsigned int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }

    putchar('\n');
}



void findMinNumberArray(const unsigned int array[MAX], unsigned int size, unsigned int i, unsigned int* result) {
    assert(size > 0     );
    assert(size < MAX   );

    if (i == size) {
        return;
    }

    *result = minFunction(*result, array[i]);

    findMinNumberArray(array, size, i + 1, result);
}

void findMaxNumberArray(const unsigned int array[MAX], unsigned int size, unsigned int i, unsigned int* result) {
    assert(size > 0     );
    assert(size <= MAX  );

    if (i == size) {
        return;
    }

    *result = maxFunction(*result, array[i]);

    findMaxNumberArray(array, size, i + 1, result);
}
