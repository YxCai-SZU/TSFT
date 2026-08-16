#include <stdint.h>

/*@
    requires ((2) <= (a) <= (100));
    requires ((2) <= (b) <= (100));
    ensures \result == (((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    int32_t x;
    int32_t y;
    int32_t result;

    x = a - 1;
    y = b - 1;

    //@ assert ((1) <= (x) <= (99));
    //@ assert ((1) <= (y) <= (99));
    //@ assert x * y <= 99 * 99;
    //@ assert x * y >= 1 * 1;

    result = x * y;
    return result;
}
