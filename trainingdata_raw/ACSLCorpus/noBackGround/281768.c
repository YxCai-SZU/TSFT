#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == (800 * (n) - (((n)) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    uint32_t y;
    int32_t z;
    int32_t res;

    //@ assert (1 <= (n) <= 100);
    x = 800 * (int32_t)n;
    y = n / 15;
    //@ assert y == ((n) / 15);
    z = (int32_t)y * 200;
    res = x - z;
    //@ assert res == (800 * (n) - (((n)) / 15) * 200);
    return res;
}
