#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (800 * (n) - ((n) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t y;
    int32_t result;

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert 800 * n <= 800 * 100;
    x = 800 * (int32_t)n;

    //@ assert (n / 15) * 200 <= 200 * 7;
    y = (int32_t)(n / 15) * 200;

    result = x - y;
    //@ assert result == (800 * (n) - ((n) / 15) * 200);
    return result;
}
