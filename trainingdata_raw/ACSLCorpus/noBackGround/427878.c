#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 8 &&
        0 <= (y) && (y) <= 8 &&
        0 <= (z) && (z) <= 100);
    ensures \result == ((x) * (y) + (z));
    ensures \result <= 1000;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    uint32_t result;

    //@ assert 0 <= x <= 8;
    //@ assert 0 <= y <= 8;
    //@ assert 0 <= z <= 100;

    //@ assert x * y <= 100;
    result = x * y + z;

    //@ assert result == x * y + z;
    //@ assert x * y <= 100;
    //@ assert x * y + z <= 200;
    //@ assert result <= 200;
    //@ assert result <= 1000;

    return result;
}
