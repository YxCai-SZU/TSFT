#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000 &&
        1 <= (y) <= 100000 &&
        1 <= (z) <= 100000 &&
        (y) + 2 * (z) <= (x));
    ensures \result <= (x - z) / (y + z);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert y + z > 0;
    result = (x - z) / (y + z);
    //@ assert result <= (x - z) / (y + z);
    return result;
}
