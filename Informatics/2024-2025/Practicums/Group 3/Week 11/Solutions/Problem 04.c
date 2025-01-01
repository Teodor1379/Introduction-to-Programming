#include <assert.h>

#include <limits.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>



#define MAX 1024



char*   buildString(                );
void    clearString(char* string    );



unsigned int countWords(const char* string);



char* findMinWord(const char* string);
char* findMaxWord(const char* string);



int main() {
    char* string = buildString();

    if (string == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    unsigned int words = countWords(string);

    printf("The number of words in the string is: %u\n", words);


    char* minWord = findMinWord(string);
    char* maxWord = findMaxWord(string);

    printf("MIN word in the string is: %s\n",   minWord);
    printf("MAX word in the string is: %s\n",   maxWord);


    clearString(minWord);
    clearString(maxWord);
    clearString(string);


    return 0;
}



char* buildString() {
    char* string = (char*)(malloc(MAX * sizeof(char)));

    if (string != NULL) {
        printf("Input the string: ");   fgets(string, MAX,  stdin   );
        printf("Output the string: ");  fputs(string,       stdout  );
    }

    string[strlen(string) - 1] = '\0';

    return string;
}

void clearString(char* string) {
    assert(string != NULL);

    free(string);

    string = NULL;
}



unsigned int countWords(const char* string) {
    assert(string != NULL);

    unsigned int words = 0;

    for (unsigned int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == ' ') {
            words = words + 1;
        }
    }

    return words + 1;
}



char* findMinWord(const char* string) {
    unsigned int length = 0;
    unsigned int result = UINT_MAX;
    unsigned int positn = 0;
    unsigned int startP = 0;

    for (unsigned int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == ' ' || string[i] == '\0') {
            if (result > length && length > 0) {
                result = length;
                positn = startP;
            }

            length = 0;

            if (string[i] != '\0') {
                startP = i + 1;
            }
        } else {
            if (length == 0) {
                startP = i;
            }

            length = length + 1;
        }
    }

    if (result > length && length > 0) {
        result = length;
        positn = startP;
    }

    char* word = (char*)(malloc((result + 1) * sizeof(char)));

    if (word != NULL) {
        strncpy(word, string + positn, result);

        word[result] = '\0';
    }

    return word;
}

char* findMaxWord(const char* string) {
    unsigned int length = 0;
    unsigned int result = 0;
    unsigned int positn = 0;
    unsigned int startP = 0;

    for (unsigned int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == ' ' || string[i] == '\0') {
            if (result < length && length > 0) {
                result = length;
                positn = startP;
            }

            length = 0;

            if (string[i] != '\0') {
                startP = i + 1;
            }
        } else {
            if (length == 0) {
                startP = i;
            }

            length = length + 1;
        }
    }

    if (result < length && length > 0) {
        result = length;
        positn = startP;
    }

    char* word = (char*)(malloc((result + 1) * sizeof(char)));

    if (word != NULL) {
        strncpy(word, string + positn, result);

        word[result] = '\0';
    }

    return word;
}
