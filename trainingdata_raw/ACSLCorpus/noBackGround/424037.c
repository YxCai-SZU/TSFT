#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> (unsigned)\result <= ((a) + (b) * 8);
    ensures \result == -1 ==> ((a) + (b) * 8) < 13;
*/
int32_t func(uint32_t a, uint32_t b) {
    uint32_t base;
    uint32_t result;
    uint32_t quotient;
    uint32_t remainder;

    base = a + b * 8;
    
    if (base < 13) {
        return -1;
    }
    
    result = base - 12;
    quotient = 0;
    remainder = result;
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant quotient <= result / 5;
        loop invariant remainder == result - quotient * 5;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
    */
    while (remainder >= 5) {
        quotient += 1;
        remainder -= 5;
    }
    
    if (remainder == 0) {
        return (int32_t)quotient;
    } else {
        return (int32_t)(quotient + 1);
    }
}
