#define _GNU_SOURCE



#include <math.h>

#include <stdio.h>
#include <stdlib.h>



void absoluteValueFunctions ();
void explogMathFunctions    ();
void powerrootFunctions     ();
void roundingFunctions      ();
void trigonometricFunctions ();
void hyperbolicFunctions    ();
void miscellaneousFunctions ();
void randomNumbersFunctions ();



int main() {
    absoluteValueFunctions  ();
    explogMathFunctions     ();
    powerrootFunctions      ();
    roundingFunctions       ();
    trigonometricFunctions  ();
    hyperbolicFunctions     ();
    miscellaneousFunctions  ();
    randomNumbersFunctions  ();


    printf("M_E Constant is: %lf\n",    M_E );

    printf("M_LOG2E     Constant is: %lf\n",    M_LOG2E );
    printf("M_LOG10E    Constant is: %lf\n",    M_LOG10E);

    printf("M_LN2       Constant is: %lf\n",    M_LN2   );
    printf("M_LN10      Constant is: %lf\n",    M_LN10  );

    printf("M_PI        Constant is: %lf\n",    M_PI        );
    printf("M_PI_2      Constant is: %lf\n",    M_PI_2      );
    printf("M_PI_4      Constant is: %lf\n",    M_PI_4      );
    printf("M_1_PI      Constant is: %lf\n",    M_1_PI      );
    printf("M_2_PI      Constant is: %lf\n",    M_2_PI      );
    printf("M_2_SQRTPI  Constant is: %lf\n",    M_2_SQRTPI  );
    printf("M_SQRT2     Constant is: %lf\n",    M_SQRT2     );

    printf("M_SQRT1_2   Constant is: %lf\n",    M_SQRT1_2   );


    return 0;
}



void absoluteValueFunctions() {
    printf("ABS function is: %d\n", abs(-1));

    printf("FABS function is: %lf\n",   fabs(-1.0));
}

void explogMathFunctions() {
    printf("EXP     function is: %lf\n",    exp     (1.0));
    printf("EXP2    function is: %lf\n",    exp2    (1.0));
    printf("EXP10   function is: %lf\n",    exp10   (1.0));

    printf("LOG     function is: %lf\n",    log     ( 1.0));
    printf("LOG2    function is: %lf\n",    log2    ( 8.0));
    printf("LOG10   function is: %lf\n",    log10   (10.0));
}

void powerrootFunctions() {
    printf("POW     function is: %lf\n",    pow(2, 2)   );
    printf("SQRT    function is: %lf\n",    sqrt(9.000) );
    printf("CBRT    function is: %lf\n",    cbrt(8.000) );
    printf("HYPOT   function is: %lf\n",    hypot(3, 4) );
}

void roundingFunctions() {
    printf("ROUND function is: %lf\n",  round(1.379));
    printf("FLOOR function is: %lf\n",  floor(1.379));
    printf("CEIL  function is: %lf\n",  ceil (1.379));
    printf("TRUNC function is: %lf\n",  trunc(1.379));
}

void trigonometricFunctions() {
    printf("SIN function is: %lf\n", sin(M_PI));
    printf("COS function is: %lf\n", cos(0.0)) ;
    printf("TAN function is: %lf\n", tan(M_PI));

    printf("ASIN function is: %lf\n", asin(1.00));
    printf("ACOS function is: %lf\n", acos(1.00));
    printf("ATAN function is: %lf\n", atan(1.00));
}

void hyperbolicFunctions() {
    printf("SINH function is: %lf\n", sinh(0.0));
    printf("COSH function is: %lf\n", cosh(0.0));
    printf("TANH function is: %lf\n", tanh(0.0));

    printf("ASINH function is: %lf\n", asinh(0.0));
    printf("ACOSH function is: %lf\n", acosh(0.0));
    printf("ATANH function is: %lf\n", atanh(0.0));
}

void miscellaneousFunctions() {
    printf("FDIM    function is: %lf\n",    fdim(9.000, 1.000));
    printf("FMIN    function is: %lf\n",    fmin(1.000, 3.000));
    printf("FMAX    function is: %lf\n",    fmax(9.000, 7.000));
}

void randomNumbersFunctions() {
    int number1 = rand();
    int number2 = rand();
    int number3 = rand();


    printf("The RAND() function is: %d\n",  number1);
    printf("The RAND() function is: %d\n",  number2);
    printf("The RAND() function is: %d\n",  number3);
}
