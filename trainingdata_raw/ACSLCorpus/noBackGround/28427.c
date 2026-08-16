#include <stdint.h>
/*@
    requires 1 <= x && x <= 9;
    requires 1 <= y && y <= 9;
    ensures \result == x * y;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    //@ assert (1 <= (x) && (x) <= 9);
    //@ assert (1 <= (y) && (y) <= 9);
    //@ assert x * y <= 81;
    return x * y;
}
