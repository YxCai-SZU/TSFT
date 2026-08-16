#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t h)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (h) <= 100 &&         (h) % 2 == 0);
    
    //@ assert (a + b) * h <= 200 * 100;
    //@ assert (a + b) * h >= 2 * 1;
    
    result = (a + b) * h / 2;
    
    //@ assert result == (((a) + (b)) * (h) / 2);
    
    return result;
}
