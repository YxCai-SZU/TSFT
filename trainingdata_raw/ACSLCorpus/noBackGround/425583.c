#include <stdint.h>

/*@
    requires x <= 10000;
    requires y <= 10000;
    ensures \result <= x + y;
    ensures \result == (x > y ? x : y);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t sum;
    uint32_t result;

    sum = x + y;
    result = (x > y) ? x : y;

    //@ assert result <= x + y;

    return result;
}
