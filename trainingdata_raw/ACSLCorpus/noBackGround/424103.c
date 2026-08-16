#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (800 * (n) - 200 * (((n)) / 15));
*/
int32_t func(uint32_t n) {
    int32_t x;
    uint32_t quotient;
    uint32_t remainder;
    int32_t y;
    int32_t result;
    
    x = 800 * (int32_t)n;
    
    quotient = 0;
    remainder = n;
    
    /*@
        loop invariant (1 <= (n) && (n) <= 100);
        loop invariant 0 <= quotient <= ((n) / 15);
        loop invariant remainder == n - quotient * 15;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15) {
        //@ assert remainder >= 15;
        quotient = quotient + 1;
        remainder = remainder - 15;
    }
    
    y = 200 * (int32_t)quotient;
    
    if (x >= y) {
        result = x - y;
    } else {
        result = y - x;
    }
    
    //@ assert x == 800 * (int32_t)n;
    //@ assert y == 200 * (int32_t)((n) / 15);
    //@ assert result == (800 * (n) - 200 * (((n)) / 15));
    
    return result;
}
