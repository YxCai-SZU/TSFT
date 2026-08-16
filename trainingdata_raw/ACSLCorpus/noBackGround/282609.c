#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (k) && (k) <= 100);
    ensures \result == (((n) - 1) * ((k) - 1));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t k)
{
    uint32_t n_unsigned;
    uint32_t k_unsigned;
    uint32_t result_unsigned;
    int32_t result;

    n_unsigned = (uint32_t)n;
    k_unsigned = (uint32_t)k;

    //@ assert n_unsigned - 1 >= 1;
    //@ assert k_unsigned - 1 >= 1;
    //@ assert n_unsigned - 1 <= 99;
    //@ assert k_unsigned - 1 <= 99;
    //@ assert (n_unsigned - 1) * (k_unsigned - 1) <= 99 * 99;

    result_unsigned = (n_unsigned - 1) * (k_unsigned - 1);
    result = (int32_t)result_unsigned;

    return result;
}
