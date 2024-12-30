#include <assert.h>

#include <stdlib.h>

#include <stdio.h>



#define MAX 1024



char*   buildString(                );
void    clearString(char* string    );



int isLowerLetter(const char character);
int isUpperLetter(const char character);
int isDigitLetter(const char character);
int isOtherLetter(const char character);



unsigned int countLowerLetters(const char* string);
unsigned int countUpperLetters(const char* string);
unsigned int countDigitLetters(const char* string);
unsigned int countOtherLetters(const char* string);



int main() {
    char* string = buildString();

    if (string == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    unsigned int result1 = countLowerLetters(string);
    unsigned int result2 = countUpperLetters(string);
    unsigned int result3 = countDigitLetters(string);
    unsigned int result4 = countOtherLetters(string);

    printf("The number of lower letters are: %u\n", result1);
    printf("The number of upper letters are: %u\n", result2);
    printf("The number of digit letters are: %u\n", result3);
    printf("The number of other letters are: %u\n", result4);


    clearString(string);


    return 0;
}



char* buildString() {
    char* string = (char*)(malloc(MAX * sizeof(char)));

    if (string != NULL) {
        printf("Input the string: ");   fgets(string, MAX,  stdin   );
        printf("Output the string: ");  fputs(string,       stdout  );
    }

    return string;
}

void clearString(char* string) {
    free(string);

    string = NULL;
}



int isLowerLetter(const char character) {
    return  character >= 'a'    &&
            character <= 'z';
}

int isUpperLetter(const char character) {
    return  character   >=  'A' &&
            character   <=  'Z';
}

int isDigitLetter(const char character) {
    return  character   >=  '0' &&
            character   <=  '9';
}

int isOtherLetter(const char character) {
    return  !isLowerLetter(character)   &&
            !isUpperLetter(character)   &&
            !isDigitLetter(character);
}



unsigned int countLowerLetters(const char* string) {
    unsigned int result = 0;

    for (unsigned int i = 0; string[i] != '\0'; ++i) {
        if (isLowerLetter(string[i])) {
            result = result + 1;
        }
    }

    return result;
}

unsigned int countUpperLetters(const char* string) {
    unsigned int result = 0;

    for (unsigned int i = 0; string[i] != '\0'; ++i) {
        if (isUpperLetter(string[i])) {
            result = result + 1;
        }
    }

    return result;
}

unsigned int countDigitLetters(const char* string) {
    unsigned int result = 0;

    for (unsigned int i = 0; string[i] != '\0'; ++i) {
        if (isDigitLetter(string[i])) {
            result = result + 1;
        }
    }

    return result;
}

unsigned int countOtherLetters(const char* string) {
    unsigned int result = 0;

    for (unsigned int i = 0; string[i] != '\0'; ++i) {
        if (isOtherLetter(string[i])) {
            result = result + 1;
        }
    }

    return result;
}
