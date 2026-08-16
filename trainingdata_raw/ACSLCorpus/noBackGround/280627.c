#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 0x49);
    ensures \result == (((x) * 100 + 7) / 11);
    assigns \nothing;
*/
uint32_t func(uint32_t x) {
    uint32_t x_scaled;
    uint32_t quotient;
    uint32_t remainder;
    uint32_t divisor;
    
    x_scaled = x * 100 + 7;
    quotient = 0;
    remainder = x_scaled;
    divisor = 11;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= x_scaled / divisor;
        loop invariant remainder == x_scaled - quotient * divisor;
        loop invariant 0 <= x_scaled && x_scaled <= 0x49 * 100 + 7;
        loop invariant remainder < x_scaled + divisor;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
    }
    
    //@ assert quotient == (((x) * 100 + 7) / 11);
    return quotient;
}
