#include <stdint.h>
/*@
    requires (1 <= (n) && (n) <= 1000000000000000000 &&
        1 <= (k) && (k) <= 1000000000000000000 &&
        (k) <= (n));
    ensures \result >= 1;
    ensures \result <= n;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    uint64_t result;
    uint64_t half_n_minus_k;
    uint64_t half_k;

    if (n == k)
    {
        result = 1;
        //@ assert result >= 1;
        //@ assert result <= n;
        return result;
    }
    else
    {
        //@ assert n > k;
        half_n_minus_k = (n - k) / 2;
        //@ assert half_n_minus_k == (n - k) / 2;
        half_k = k / 2;
        //@ assert half_k == k / 2;
        //@ assert half_n_minus_k + half_k + 1 >= 1;
        result = half_n_minus_k + half_k + 1;
        //@ assert result >= 1;
        //@ assert result <= n;
        return result;
    }
}
