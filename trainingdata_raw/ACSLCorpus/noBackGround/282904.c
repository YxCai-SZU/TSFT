#include <stdint.h>

/*@
    requires 1 <= x && x <= 100;
    ensures \result == (integer)(x * 800) - (integer)((x / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    uint32_t x_800;
    uint32_t x_div_15;
    uint32_t x_200;
    int32_t result;

    x_800 = x * 800;
    x_div_15 = x / 15;
    x_200 = x_div_15 * 200;
    result = (int32_t)x_800 - (int32_t)x_200;

    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert x_800 == ((x) * 800);
    //@ assert x_div_15 == ((x) / 15);
    //@ assert x_200 == (((x) / 15) * 200);
    //@ assert result == ((((x)) * 800) - ((((x)) / 15) * 200));

    return result;
}
