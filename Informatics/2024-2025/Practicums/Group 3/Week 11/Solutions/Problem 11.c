#include <assert.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>



#define MAX 1024



char*   buildString(                );
void    clearString(char* string    );



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

        clearString(string1);

        return 1;
    }

    string2[strlen(string2) - 1] = '\0';


    unsigned int size = strlen(string2);

    unsigned int index1 = 0;
    unsigned int index2 = 0;

    while (string1[index1] != '\0') {
        if (contains(string1, string2, index1)) {
            index1 = index1 + size;
        } else {
            string1[index2] = string1[index1];

            index1 = index1 + 1;
            index2 = index2 + 1;
        }
    }

    string1[index2] = '\0';

    printf("The string is: %s", string1);


    clearString(string1);
    clearString(string2);


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



int contains(const char* sentence, const char* word, unsigned int index) {
    assert(sentence !=  NULL    );
    assert(word     !=  NULL    );

    unsigned int index1 = index ;
    unsigned int index2 = 0     ;

    while (sentence[index1] != '\0' && word[index2] != '\0') {
        if (sentence[index1] != word[index2]) {
            return 0;
        }

        index1 = index1 + 1;
        index2 = index2 + 1;
    }

    return word[index2] == '\0';
}
