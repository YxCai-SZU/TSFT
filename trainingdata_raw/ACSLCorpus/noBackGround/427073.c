#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == 2 * 31415 * r / 10000;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t result;
    int64_t quotient = 0;
    const int64_t divisor = 10000;
    
    //@ assert 2 * 31415 <= 100000;
    
    result = 2 * 31415 * r;
    
    /*@
        loop invariant 0 <= result <= 2 * 31415 * 100;
        loop invariant (2 * 31415 * (r)) - quotient * divisor == result;
        loop invariant result >= 0;
        loop assigns result, quotient;
        loop variant result;
    */
    while (result >= divisor) {
        result -= divisor;
        quotient += 1;
    }
    
    //@ assert quotient * divisor + result == 2 * 31415 * r;
    
    return quotient;
}
