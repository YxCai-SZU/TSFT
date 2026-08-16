#include <stdint.h>

/*@
    requires 1 <= n && n <= 100;
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    uint32_t x;
    uint32_t y;
    int32_t res;

    x = n / 15;
    y = n % 15;

    //@ assert n == 15 * x + y;
    //@ assert n * 800 == 800 * (15 * x + y);
    //@ assert x * 200 == 200 * x;

    res = (int32_t)(n * 800 - x * 200);
    return res;
}
