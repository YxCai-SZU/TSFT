#include <limits.h>

/*@
    requires (1 <= (x) <= 1000);
    ensures \result >= 0;
    ensures \result * 3 <= x;
    ensures x < (\result + 1) * 3;
    assigns \nothing;
*/
int func(int x) {
    int quotient;
    int remainder;
    int divisor;
    
    quotient = 0;
    divisor = 3;
    
    if (x < 0) {
        remainder = -x;
    } else {
        remainder = x;
    }
    
    /*@
        loop invariant 0 <= remainder <= x;
        loop invariant 0 <= quotient <= x / 3;
        loop invariant (1 <= (x) <= 1000);
        loop invariant remainder == x - quotient * divisor;
        loop assigns remainder, quotient;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }
    
    if (x < 0) {
        quotient = -quotient;
    }
    
    //@ assert (1 <= (x) <= 1000);
    //@ assert 0 <= quotient * 3 <= 1000 * 3;
    
    return quotient;
}
