#include <stdio.h>

int main() {
    unsigned int n = 0;
    unsigned int s = 0;
    unsigned int r = 0;

    printf("Enter the number N: "); scanf("%u", &n);
    printf("Enter the number S: "); scanf("%u", &s);
    printf("Enter the number R: "); scanf("%u", &r);

    n = (n |  (1 << r));
    n = (n & ~(1 << s));

    printf("The new number N is: %u\n", n);

    return 0;
}
