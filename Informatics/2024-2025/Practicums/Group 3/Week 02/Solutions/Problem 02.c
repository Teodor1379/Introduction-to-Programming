#include <stdio.h>


int main() {
    int     a   = 0     ;
    double  b   = 0.0   ;
    char    c   = '\0'  ;

    scanf("%d %lf %c", &a, &b, &c);

    printf("%d\n",    a);
    printf("%lf\n",   b);
    printf("%c\n",    c);

    return 0;
}
