#include <stdint.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (b) <= 100) && (0 <= (c) <= 100);
    ensures \result <= ((a) * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result;

    //@ assert ((a) * (b)) <= 10000;
    
    if (c > a * b) {
        result = a * b;
    } else {
        result = c;
    }
    
    return result;
}
