#include <stdint.h>

/*@
    requires ((a) <= 1000) && ((b) <= 1000) && ((c) <= 1000) && ((d) <= 1000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b && \result >= c * d;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t result;

    //@ assert a * b <= 1000000;
    //@ assert c * d <= 1000000;
    
    if (a * b > c * d) {
        result = a * b;
    } else {
        result = c * d;
    }
    
    //@ assert result <= 1000000;
    return result;
}
