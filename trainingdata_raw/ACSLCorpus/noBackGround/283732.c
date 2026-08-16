#include <stdint.h>

/*@
    requires ((a) >= 1 && (b) >= 1 && (c) >= 1 &&
        (a) <= 100 && (b) <= 100 && (c) <= 100);
    ensures \result == (((a) + (b) + (c) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert a + b + c + 1 <= 400;
    //@ assert (a + b + c + 1) / 2 <= 200;
    
    result = (a + b + c + 1) / 2;
    return result;
}
