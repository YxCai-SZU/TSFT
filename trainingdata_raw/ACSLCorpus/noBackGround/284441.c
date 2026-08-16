#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t a_mod, b_mod, sum_mod;
    int32_t result;

    a_mod = a % 3;
    b_mod = b % 3;
    sum_mod = (a + b) % 3;

    if (a_mod == 0 || b_mod == 0 || sum_mod == 0)
    {
        //@ assert a_mod == 0 || b_mod == 0 || sum_mod == 0;
        result = 0;
    }
    else
    {
        //@ assert a_mod != 0 && b_mod != 0 && sum_mod != 0;
        result = 1;
    }

    return result;
}
