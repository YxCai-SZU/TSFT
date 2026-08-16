#include <stdint.h>

/*@
    requires (1 <= (x) <= 32);
    requires (1 <= (y) <= 32);
    ensures \result <= 32;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert (1 <= (x) <= 32);
    //@ assert (1 <= (y) <= 32);

    //@ assert (((x) + (y)) / 2) <= 32;

    if (((x + y) / 2) <= 32) {
        result = (x + y) / 2;
    } else {
        result = 32;
    }

    //@ assert result <= 32;
    return result;
}
