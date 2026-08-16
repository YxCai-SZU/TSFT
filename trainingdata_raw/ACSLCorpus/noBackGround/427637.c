#include <stdint.h>

/*@
    requires (0 <= (x) <= 100) && (0 <= (y) <= 100) && (0 <= (z) <= 100);
    ensures \result == ((((x) * (y))) * (z));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    // Variable declarations at top of scope
    uint32_t intermediate;
    uint32_t result;

    //@ assert (0 <= (x) <= 100);
    //@ assert (0 <= (y) <= 100);
    //@ assert (0 <= (z) <= 100);

    //@ assert 0 <= x * y <= 10000;
    intermediate = x * y;

    //@ assert 0 <= intermediate * z <= 1000000;
    result = intermediate * z;

    //@ assert result == (x * y) * z;
    return result;
}
