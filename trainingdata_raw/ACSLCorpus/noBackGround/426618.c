#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 100);
    ensures ((\result) >= -(c) && (\result) <= (a));
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int64_t k)
{
    int32_t result = 0;
    int64_t remaining = k;
    int32_t tmp = a;

    if (remaining >= 1)
    {
        //@ assert remaining >= 1;
        result += (tmp < 1) ? tmp : 1;
        remaining -= 1;
        tmp -= 1;
    }

    tmp = b;

    if (remaining >= 1)
    {
        //@ assert remaining >= 1;
        remaining -= 1;
        tmp -= 1;
    }

    result -= (tmp < 1) ? tmp : 1;

    //@ assert result >= -c;
    //@ assert result <= a;

    return result;
}
