#include <limits.h>

/*@
    requires 1 <= x <= 10000;
    ensures \result == (x / 3) * 3;
 */
int func(int x) {
    int quotient;
    int remainder;
    int divisor;
    int original_x;

    original_x = x;
    quotient = 0;
    divisor = 3;

    if (x < 0) {
        remainder = -x;
    } else {
        remainder = x;
    }

    /*@
        loop invariant 0 <= remainder <= 10000;
        loop invariant 0 <= quotient <= 3333;
        loop invariant remainder == original_x - quotient * divisor ||
                       remainder == -original_x - quotient * divisor;
        loop invariant 1 <= original_x <= 10000;
        loop assigns remainder, quotient;
        loop variant remainder;
     */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }

    if (original_x < 0) {
        quotient = -quotient;
    }

    //@ assert quotient * divisor == (original_x / 3) * 3;
    return quotient * divisor;
}
