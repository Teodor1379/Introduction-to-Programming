#include <assert.h>

#include <stdio.h>

#include <stdlib.h>



#define MAX 1024



void clearStandardInput();



unsigned int readSize();



char* buildString(              unsigned int size   );
void  clearString(char** string                     );



void generateParentheses(unsigned int number1, unsigned int number2, unsigned int index, char** string);



int main() {
    unsigned int size = readSize();

    char* string = buildString(2 * size);

    generateParentheses(size, size, 0, &string);

    clearString(&string);

    return 0;
}



void clearStandardInput() {
    int c = 0;

    while ((c = getchar()) && c != '\n' && c != EOF);
}



unsigned int readSize() {
    unsigned int size   =   0;
    int inputArgument   =   0;

    do {
        printf("Enter the size of the string: ");

        inputArgument = scanf("%u", &size);

        if (inputArgument != 1) {
            clearStandardInput();
        }
    } while (inputArgument != 1 || size == 0 || size > MAX);

    return size;
}



char* buildString(unsigned int size) {
    char* string = (char*)(calloc(size + 1, sizeof(char)));

    return string;
}

void clearString(char** string) {
    assert(*string != NULL);

    free(*string);

    *string = NULL;
}



void generateParentheses(unsigned int number1, unsigned int number2, unsigned int index, char** string) {
    if (number1 == 0 && number2 == 0) {
        (*string)[index] = '\0';

        printf("Generation is: %s\n", *string);

        return;
    }

    if (number1 == number2) {
        (*string)[index] = '(';
        generateParentheses(number1 - 1, number2, index + 1, string);
    } else if (number1 == 0) {
        (*string)[index] = ')';
        generateParentheses(number1, number2 - 1, index + 1, string); 
    } else if (number2 == 0) {
        (*string)[index] = '(';
        generateParentheses(number1 - 1, number2, index + 1, string);
    } else {
        (*string)[index] = '('; generateParentheses(number1 - 1, number2, index + 1, string);
        (*string)[index] = ')'; generateParentheses(number1, number2 - 1, index + 1, string);
    }
}
