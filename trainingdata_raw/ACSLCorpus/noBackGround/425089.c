#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result <= c;
    ensures \result <= ((a) + ((b) / 2));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t result = 0;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100);
    
    if (b >= a * 2) {
        result = a + (b - a * 2) / 4;
    } else {
        result = b / 2;
    }

    //@ assert result <= ((a) + ((b) / 2));
    
    if (result < c) {
        return result;
    } else {
        return c;
    }
}
