#include <stdint.h>

/*@
    requires (1 <= (x) && (x) < 100) && (1 <= (y) && (y) < 100);
    ensures \result == x * y;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    //@ assert (1 <= (x) && (x) < 100);
    //@ assert (1 <= (y) && (y) < 100);
    //@ assert x <= 99;
    //@ assert y <= 99;
    //@ assert x * y <= 99 * 99;

    return x * y;
}
