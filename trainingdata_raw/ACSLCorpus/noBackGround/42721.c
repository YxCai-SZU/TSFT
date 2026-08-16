#include <stdint.h>

/*@
    requires (1 <= (x) <= 100 &&
        1 <= (y) <= 100 &&
        (y) % 2 == 0);
    ensures \result == ((x) + (y) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t x, uint64_t y)
{
    // Variable declarations at top of scope
    uint64_t result;

    //@ assert y / 2 >= 0;
    //@ assert x + y / 2 >= 1;
    //@ assert x + y / 2 <= 200;

    result = x + y / 2;
    return result;
}
