#include <stdint.h>

/*@
    requires 1 <= a <= 1000000000000000;
    ensures (a % 2 == 0 ==> \result == a / 2);
    ensures (a % 2 == 1 ==> \result == (a - 1) / 2 + 1);
*/
uint64_t func(uint64_t a) {
    uint64_t quotient;
    uint64_t remainder;
    
    quotient = 0;
    remainder = a;
    
    /*@
        loop invariant 0 <= quotient <= a / 2;
        loop invariant remainder == a - 2 * quotient;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        quotient += 1;
        remainder -= 2;
    }
    
    if (remainder == 1) {
        quotient += 1;
    }
    
    //@ assert quotient == a / 2 || quotient == (a - 1) / 2 + 1;
    
    return quotient;
}
