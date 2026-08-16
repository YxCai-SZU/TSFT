#include <limits.h>

/*@
    requires (1 <= (x) <= 1000);
    ensures (1 <= (\result) <= 1000 && (\result) * 3 >= (x) && (x) * 3 >= (\result));
*/
int func(int x) {
    int quotient;
    int remainder;
    int result;
    
    quotient = 0;
    remainder = x;
    
    /*@
        loop invariant 0 <= quotient <= x / 3;
        loop invariant remainder == x - quotient * 3;
        loop invariant remainder >= 0;
        loop invariant (1 <= (x) <= 1000);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 3) {
        remainder -= 3;
        quotient += 1;
    }
    
    if (remainder == 0) {
        result = quotient;
    } else {
        result = quotient + 1;
    }
    
    //@ assert 1 <= result <= 1000;
    //@ assert result * 3 >= x;
    //@ assert x * 3 >= result;
    
    return result;
}
