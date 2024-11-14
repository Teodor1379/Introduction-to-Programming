#include <stdio.h>

int main() {
    unsigned int current = 0;

    scanf("%u", &current);

    unsigned int min = current;
    unsigned int max = current;

    while (1) {
        scanf("%u", &current);

        if (current == 0) {
            break;
        }

        if (min < current) {
            min = current;
        }

        if (max > current) {
            max = current;
        }
    }

    printf("The min number is: %u\n", min);
    printf("The max number is: %u\n", max);

    return 0;
}
