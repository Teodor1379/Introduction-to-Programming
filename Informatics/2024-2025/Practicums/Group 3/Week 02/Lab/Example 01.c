#include <stdio.h>


int main() {
    printf("%d\n",   1  );  //  Integer (Signed)
    printf("%d\n",  -3  );  //  Integer (Signed)

    printf("%i\n",   7  );  //  Integer (Signed)
    printf("%i\n",  -9  );  //  Integer (Signed)

    printf("%u\n",  -1  );  //  Unsigned Integer

    printf("%f\n", 1.000);  //  Float   Number
    printf("%lf\n", 3.00);  //  Double  Number

    printf("%e\n", 7.000);  //  Exponential Notation
    printf("%E\n", 9.000);  //  Exponential Notation

    printf("%o\n",  16  );  //  8-Base Notation
    printf("%x\n",  16  );  // 16-Base Notation
    printf("%X\n",  16  );  // 16-Base Notation

    printf("%c\n",  'J' );  //  Signed Character

    printf("%s\n",  "TJ");  //  C-String

    printf("%p\n", NULL);   //  Pointer

    return 0;
}
