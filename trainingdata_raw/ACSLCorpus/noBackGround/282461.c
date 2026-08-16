#include <stdint.h>
/*@
    requires (1 <= (x) <= 100000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t x_500;
    uint32_t x_5;
    uint32_t result;

    x_500 = x / 500;
    //@ assert x_500 == x / 500;

    x_5 = (x - x_500 * 500) / 5;
    //@ assert x_5 == (x - x_500 * 500) / 5;

    result = x_500 * 1000 + x_5 * 5;
    //@ assert result == (x / 500) * 1000 + ((x % 500) / 5) * 5;

    return result;
}
