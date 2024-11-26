#include <stdio.h>

int main() {
    char letter = '\0';

    printf("Enter the letter: ");

    scanf("%c", &letter);

    printf("The lowercase is: %c\n", letter + 32);

    return 0;
}
