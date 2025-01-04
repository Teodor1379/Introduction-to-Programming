#include <assert.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>



#define MAX 1024



char*   buildString(                );
void    clearString(char** string   );



void replace(char* sentence, const char* word1, const char* words);



int contains(const char* sentence, const char* word, unsigned int index);



int main() {
    char* string1 = buildString();

    if (string1 == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }

    char* string2 = buildString();

    if (string2 == NULL) {
        puts("Allocating Memory... ERROR!");

        clearString(&string1);

        return 1;
    }

    char* string3 = buildString();

    if (string3 == NULL) {
        puts("Allocating Memory... ERROR!");

        clearString(&string1);
        clearString(&string2);

        return 1;
    }

    unsigned int size1 = strlen(string2);
    unsigned int size2 = strlen(string3);

    string2[size1 - 1] = '\0';
    string3[size2 - 1] = '\0';


    replace(string1, string2, string3);

    printf("\n\n\nThe result sentence is: %s", string1);


    clearString(&string1);
    clearString(&string2);
    clearString(&string3);


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

void clearString(char** string) {
    assert(*string != NULL);

    free(*string);

    *string = NULL;
}



void replace(char* sentence, const char* word1, const char* word2) {
    assert(sentence != NULL);

    assert(word1 != NULL);
    assert(word2 != NULL);

    char* result = (char*)(malloc(MAX * sizeof(char)));

    unsigned int index1 = 0;
    unsigned int index2 = 0;

    unsigned int size1 = strlen(word1);
    unsigned int size2 = strlen(word2);

    while (sentence[index1] != '\0') {
        if (contains(sentence, word1, index1)) {
            for (unsigned int i = 0; i < size2; ++i) {
                result[index2] = word2[i];

                index2 = index2 + 1;
            }

            index1 = index1 + size1;
        } else {
            result[index2] = sentence[index1];

            index1 = index1 + 1;
            index2 = index2 + 1;
        }
    }

    result[index2] = '\0';

    char temp[MAX];

    strcpy(temp, sentence);
    strcpy(sentence, result);
    strcpy(result, temp);

    clearString(&result);
}



int contains(const char* sentence, const char* word, unsigned int index) {
    assert(sentence != NULL);

    assert(word != NULL);

    unsigned int index1 =   index   ;
    unsigned int index2 =   0       ;

    while (sentence[index1] != '\0' && word[index2] != '\0') {
        if (sentence[index1] != word[index2]) {
            return 0;
        }

        index1 = index1 + 1;
        index2 = index2 + 1;
    }

    return word[index2] == '\0';
}
