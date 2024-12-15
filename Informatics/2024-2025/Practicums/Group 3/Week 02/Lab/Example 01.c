#include <stdio.h>



int main() {
    printf("%d\n",   1  );                      //  Integer (Signed)
    printf("%d\n",  -3  );                      //  Integer (Signed)
    printf("%i\n",   7  );                      //  Integer (Signed)
    printf("%i\n",  -9  );                      //  Integer (Signed)

    printf("%hd\n",  1  );                      //  Short Integer (Signed)
    printf("%hd\n", -3  );                      //  Short Integer (Signed)
    printf("%hi\n",  7  );                      //  Short Integer (Signed)
    printf("%hi\n", -9  );                      //  Short Integer (Signed)

    printf("%ld\n", (long int)( 1)  );          //  Long Integer (Signed)
    printf("%ld\n", (long int)(-3)  );          //  Long Integer (Signed)
    printf("%li\n", (long int)( 7)  );          //  Long Integer (Signed)
    printf("%li\n", (long int)(-9)  );          //  Long Integer (Signed)

    printf("%lld\n", (long long int)( 1)    );  //  Long Long Integer (Signed)
    printf("%lld\n", (long long int)(-3)    );  //  Long Long Integer (Signed)
    printf("%lli\n", (long long int)( 7)    );  //  Long Long Integer (Signed)
    printf("%lli\n", (long long int)(-9)    );  //  Long Long Integer (Signed)


    printf("%u\n",   1  );                              //  Integer (Unsigned)
    printf("%u\n",  -3  );                              //  Integer (Unsigned)

    printf("%hu\n",  7  );                              //  Short Integer (Unsigned)
    printf("%hu\n", -9  );                              //  Short Integer (Unsigned)

    printf("%lu\n", (long unsigned int)( 1) );          //  Long Integer (Unsigned)
    printf("%lu\n", (long unsigned int)(-3) );          //  Long Integer (Unsigned)

    printf("%llu\n", (long long unsigned int)( 7)   );  //  Long Long Integer (Unsigned)
    printf("%llu\n", (long long unsigned int)(-9)   );  //  Long Long Integer (Unsigned)


    printf("%f\n",  1.000);                 //  Float       Number (Lower-Case for nan, inf, infinity)
    printf("%F\n",  9.000);                 //  Float       Number (Upper-Case for NAN, INF, INFINITY)
    printf("%lf\n", 1.000);                 //  Double      Number (Lower-Case for nan, inf, infinity)
    printf("%lF\n", 3.000);                 //  Double      Number (Upper-Case for NAN, INF, INFINITY)

    printf("%Lf\n", (long double)(7.000));  //  Long Double Number (Lower-Case for nan, inf, infinity)
    printf("%LF\n", (long double)(9.000));  //  Long Double Number (Upper-Case for NAN, INF, INFINITY)

    printf("%e\n",  1.000);                 //  Scientific Notation (Mantissa, Lower-Case Exponent, Special Numbers)
    printf("%E\n",  9.000);                 //  Scientific Notation (Mantissa, Upper-Case Exponent, Special Numbers)
    printf("%le\n", 1.000);                 //  Scientific Notation (Mantissa, Lower-Case Exponent, Special Numbers)
    printf("%lE\n", 3.000);                 //  Scientific Notation (Mantissa, Upper-Case Exponent, Special Numbers)

    printf("%Le\n", (long double)(7.000));  //  Scientific Notation (Mantissa, Lower-Case Exponent, Special Numbers)
    printf("%LE\n", (long double)(9.000));  //  Scientific Notation (Mantissa, Upper-Case Exponent, Special Numbers)

    printf("%g\n",  1.000);                 //  Alias of %f or %e
    printf("%G\n",  9.000);                 //  Alias of %F or %E
    printf("%lg\n", 1.000);                 //  Alias of %f or %e
    printf("%lG\n", 3.000);                 //  Alias of %F or %E

    printf("%Lg\n", (long double)(7.000));  //  Alias of %f or %e
    printf("%LG\n", (long double)(9.000));  //  Alias of %F or %E


    printf("%o\n",   16  );                     //  8-Base Notation (Octal Decimal Number)
    printf("%ho\n",  16  );                     //  8-Base Notation (Octal Decimal Number)

    printf("%lo\n",  (long int)     ( 16)   );  //  8-Base Notation (Octal Decimal Number)

    printf("%llo\n", (long long int)(-16)   );  //  8-Base Notation (Octal Decimal Number)


    printf("%x\n",   16  );                                 // 16-Base Notation (Hexadecimal Decimal Number, Lower-Case)
    printf("%X\n",   16  );                                 // 16-Base Notation (Hexadecimal Decimal Number, Upper-Case)
    printf("%hx\n",  16  );                                 // 16-Base Notation (Hexadecimal Decimal Number, Lower-Case)
    printf("%hX\n",  16  );                                 // 16-Base Notation (Hexadecimal Decimal Number, Upper-Case)

    printf("%lx\n",  (long int)         ( 16)   );          // 16-Base Notation (Hexadecimal Decimal Number, Lower-Case)
    printf("%lX\n",  (long unsigned int)(-16)   );          // 16-Base Notation (Hexadecimal Decimal Number, Upper-Case)

    printf("%llx\n", (long long int)            ( 16)   );  // 16-Base Notation (Hexadecimal Decimal Number, Lower-Case)
    printf("%llX\n", (long long unsigned int)   (-16)   );  // 16-Base Notation (Hexadecimal Decimal Number, Upper-Case)

    printf("%a\n",  1.000);                                 // 16-Base Notation (Hexadecimal Real Number, Lower-Case)
    printf("%A\n",  9.000);                                 // 16-Base Notation (Hexadecimal Real Number, Upper-Case)
    printf("%la\n", 1.000);                                 // 16-Base Notation (Hexadecimal Real Number, Lower-Case)
    printf("%lA\n", 3.000);                                 // 16-Base Notation (Hexadecimal Real Number, Upper-Case)

    printf("%La\n", (long double)(7.000));                  // 16-Base Notation (Hexadecimal Real Number, Lower-Case)
    printf("%LA\n", (long double)(9.000));                  // 16-Base Notation (Hexadecimal Real Number, Upper-Case)


    printf("%c\n",  'J' );  //  Character (Signed   )
    printf("%c\n",  -1  );  //  Character (Unsigned )


    printf("%s\n",  "TJ");  //  C-String


    int a = 1; int *pa = &a;
    int b = 1; int *pb = &b;
    int c = 1; int *pc = &c;

    printf("%p\n", NULL         );  //  Pointer (NULL)
    printf("%p\n", (void*)(pa)  );  //  Pointer (to a)
    printf("%p\n", (void*)(pb)  );  //  Pointer (to b)
    printf("%p\n", (void*)(pc)  );  //  Pointer (to b)

    return 0;
}
