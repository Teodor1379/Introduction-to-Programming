#include <stdio.h>

int main() {
    unsigned int number = 0;

    do {
        printf("Guess the number: ");
        scanf("%u", &number);

        if (number == 3) {
            break;
        }

    } while (number > 0);

    return 0;
}
