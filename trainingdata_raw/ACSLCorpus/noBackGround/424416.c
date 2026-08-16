#include <stdbool.h>

/*@
    requires a > 0 && b > 0 && c > 0;
    requires a <= 100 && b <= 100 && c <= 100;
    ensures \result == true;
*/
bool non_linear_arith_example(unsigned int a, unsigned int b, unsigned int c)
{
    // Declare all variables at the top
    bool result;

    //@ assert ((a) > 0 && (b) > 0 && (c) > 0 &&         (a) <= 100 && (b) <= 100 && (c) <= 100);

    //@ assert a * b <= 10000;
    //@ assert a * c <= 10000;
    //@ assert b * c <= 10000;

    //@ assert a * b + a * c <= 20000;
    //@ assert a * b + b * c <= 20000;
    //@ assert a * c + b * c <= 20000;

    //@ assert a * b + a * c + b * c <= 30000;
    //@ assert a * b + b * c + c * a <= 30000;
    //@ assert a * c + b * c + c * a <= 30000;

    result = true;
    return result;
}
