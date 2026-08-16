#include <stdint.h>

/*@
    requires x <= 1000000000;
    ensures \result == (x / 500 * 1000) + ((x % 500) / 5 * 5);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t x_500;
    uint64_t x_5;
    uint64_t result;

    x_500 = x / 500;
    x_5 = (x - x_500 * 500) / 5;
    result = x_500 * 1000 + x_5 * 5;

    //@ assert ((x_500) >= 0 && (x_500) <= 1000000000);
    //@ assert ((x_5) >= 0 && (x_5) <= 1000000000);
    //@ assert result == ((x_500) * 1000 + (x_5) * 5);

    return result;
}
