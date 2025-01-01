#include <assert.h>

#include <stdlib.h>

#include <stdio.h>

#include <string.h>



#define MAX 1024



char*   buildString(                );
void    clearString(char* string    );



void reverseString(char* string                                             );
void reverseSingle(char* string, unsigned int index1, unsigned int index2   );



int main() {
    char* string = buildString();

    if (string == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    reverseString(string);

    unsigned int index1 = 0;
    unsigned int index2 = 0;
    unsigned int index3 = 0;

    while (string[index3] != '\0') {
        if (string[index3] == ' ' && string[index3 - 1] != ' ') {
            index2 = index3 - 1;

            reverseSingle(string, index1, index2);
        } else if (string[index3] != ' ' && (index3 == 0 || string[index3 - 1] == ' ')) {
            index1 = index3;
        }

        index3 = index3 + 1;
    }

    reverseSingle(string, index1, index3 - 1);

    printf("The string is: %s\n", string);


    clearString(string);


    return 0;
}



char* buildString() {
    char* string = (char*)(malloc(MAX * sizeof(char)));

    if (string != NULL) {
        printf("Input the string: ");   fgets(string, MAX,  stdin   );
        printf("Output the string: ");  fputs(string,       stdout  );

        string[strlen(string) - 1] = '\0';
    }

    return string;
}

void clearString(char* string) {
    assert(string != NULL);

    free(string);

    string = NULL;
}



void reverseString(char* string) {
    assert(string != NULL);

    unsigned int size = strlen(string);

    for (unsigned int i = 0; i < size / 2; ++i) {
        char temp = '\0';

        temp                    =   string[i]           ;
        string[i]               =   string[size - i - 1];
        string[size - i - 1]    =   temp                ;
    }
}

void reverseSingle(char* string, unsigned int index1, unsigned int index2) {
    assert(string != NULL);

    assert(index1 < strlen(string));
    assert(index2 < strlen(string));

    unsigned int size = index2 - index1 + 1;

    for (unsigned int i = 0; i < size / 2; ++i) {
        char temp = '\0';

        temp                =   string[index1 + i]  ;
        string[index1 + i]  =   string[index2 - i]  ;
        string[index2 - i]  =   temp                ;
    }
}
