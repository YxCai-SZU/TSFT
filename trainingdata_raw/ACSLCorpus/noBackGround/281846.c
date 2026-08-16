#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
    ensures \result >= (110 * (n));
    ensures \result <= (110 * (n) + ((m) * 20 + 1));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t result;
    int32_t x;

    x = 110 * (int32_t)n + ((int32_t)m * 20 + 1);

    if (x > 110 * (int32_t)n)
    {
        //@ assert x > 110 * (int32_t)n;
        result = 110 * (int32_t)n;
    }
    else
    {
        //@ assert x <= 110 * (int32_t)n + ((int32_t)m * 20 + 1);
        result = x;
    }

    return result;
}
