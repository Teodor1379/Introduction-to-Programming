#include <assert.h>

#include <stdlib.h>

#include <stdio.h>



#define MAX 1024



char*   buildString(                );
void    clearString(char* string    );



void encode(char* string);



unsigned int countEqualLetters(const char* string, unsigned int index);



unsigned int reverseNumber(unsigned int number);



int main() {
    char* string = buildString();

    if (string == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    encode(string);

    printf("The string is: %s", string);


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
    assert(string != NULL);

    free(string);

    string = NULL;
}



void encode(char* string) {
    assert(string != NULL);

    unsigned int index1 = 0;
    unsigned int index2 = 0;

    while (string[index1] != '\0') {
        unsigned int currentCount = countEqualLetters(string, index1);

        char currentCharacter = string[index1];

        if (currentCount >= 4) {
            string[index2] = '('; index2 = index2 + 1;

            unsigned int reversed = reverseNumber(currentCount);

            while (reversed > 0) {
                string[index2] = '0' + (reversed % 10);
                index2 = index2 + 1; reversed = reversed / 10;
            }

            unsigned int temp = currentCount;

            while (temp % 10 == 0) {
                string[index2] = '0';

                index2 = index2 + 1;

                temp = temp / 10;
            }

            string[index2] = currentCharacter;
            index2 = index2 + 1;

            string[index2] = ')';
            index2 = index2 + 1;

            index1 = index1 + currentCount;
        } else {
            string[index2] = currentCharacter;

            index1 = index1 + 1;
            index2 = index2 + 1;
        }
    }

    string[index2] = '\0';
}



unsigned int countEqualLetters(const char* string, unsigned int index) {
    assert(string != NULL);

    unsigned int counter = 1;

    char character = string[index];

    index = index + 1;

    while (string[index] != '\0' && string[index] == character) {
        counter = counter + 1;
        index   = index   + 1;
    }

    return counter;
}



unsigned int reverseNumber(unsigned int number) {
    unsigned int result = 0;

    while (number > 0) {
        result = result * 10;
        result = result + number % 10;

        number = number / 10;
    }

    return result;
}
