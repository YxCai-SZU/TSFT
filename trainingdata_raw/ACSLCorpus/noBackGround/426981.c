#include <limits.h>

/*@
    requires (1 <= (x) <= 179);
    ensures \result == ((x) / 3) * 3;
    ensures \result >= 0;
    ensures \result <= x;
*/
int func(int x) {
    int quotient;
    int remainder;
    int divisor;
    
    quotient = 0;
    remainder = (x < 0) ? -x : x;
    divisor = 3;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= ((x) / 3);
        loop invariant remainder >= 0;
        loop invariant remainder + quotient * divisor == x;
        loop invariant (1 <= (x) <= 179);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        remainder -= divisor;
        quotient += 1;
    }
    
    if (x < 0) {
        quotient = -quotient;
    }
    
    //@ assert quotient == ((x) / 3);
    
    return quotient * 3;
}
