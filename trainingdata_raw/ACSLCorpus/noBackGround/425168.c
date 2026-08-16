#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result >= 0;
    ensures \result == 0 ==> n % 1000 == 0;
*/
int32_t func(uint32_t n)
{
    uint32_t n_mod_1000;
    uint32_t n_div_1000;
    int32_t result;

    n_mod_1000 = n % 1000;
    n_div_1000 = n / 1000;
    result = -1;

    if (n_mod_1000 == 0)
    {
        result = 0;
    }
    else
    {
        if (n_mod_1000 <= 500 && n_div_1000 < 1000)
        {
            result = (int32_t)(1000 - n_mod_1000);
        }
        else
        {
            //@ assert n_div_1000 < 1000;
            n_div_1000 += 1;
            n_mod_1000 = n_div_1000 * 1000 - n;

            if (n_mod_1000 < 500)
            {
                result = (int32_t)n_mod_1000;
            }
            else
            {
                result = (int32_t)(1000 - n_mod_1000);
            }
        }
    }

    //@ assert result >= 0;
    return result;
}
