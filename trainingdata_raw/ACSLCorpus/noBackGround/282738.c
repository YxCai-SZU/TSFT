#include <stdint.h>

/*@
    requires (1 <= (x) <= 100) && (1 <= (y) <= 100) && (1 <= (z) <= 100);
    ensures \result == ((x + y) * (z));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    uint32_t result;

    //@ assert 1 <= x + y <= 200;
    //@ assert 1 <= z <= 100;
    //@ assert (x + y) * z <= 20000;

    result = (x + y) * z;
    return result;
}
