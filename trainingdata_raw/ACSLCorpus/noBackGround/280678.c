#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t y;
    int32_t r;
    int32_t result;

    x = 800;
    y = 200;
    r = (int32_t)(n / 15);

    //@ assert r == (int32_t)(n / 15);
    //@ assert x * (int32_t)n - r * y == ((n) * 800 - ((n) / 15) * 200);

    result = x * (int32_t)n - r * y;
    return result;
}
