#include <assert.h>

#include <stdlib.h>

#include <stdio.h>



#define MAX 1024



char*   buildString(                );
void    clearString(char* string    );



void transformString(char* string);



int main() {
    char* string = buildString();

    if (string == NULL) {
        puts("Allocating Memory... ERROR!");

        return 1;
    }


    transformString(string);

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
    free(string);

    string = NULL;
}



void transformString(char* string) {
    assert(string != NULL);

    unsigned int index1 = 0;
    unsigned int index2 = 0;

    while (string[index1] != '\0') {
        if (string[index1] != ' ' || (string[index1] == ' ' && string[index1 - 1] != ' ')) {
            string[index2] = string[index1];

            index2 = index2 + 1;
        }

        index1 = index1 + 1;
    }

    string[index2] = '\0';
}
