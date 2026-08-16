#include <stdint.h>

/*@
    requires 1 <= n <= 1000000000;
    ensures ((\result) >= 2 * ((n) / 11));
    ensures ((\result) <= 2 * ((n) / 11) + 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t res_base;
    uint64_t rem;
    uint64_t res;

    res_base = (n / 11) * 2;
    rem = n % 11;

    if (rem == 0)
    {
        res = res_base;
    }
    else if (rem < 7)
    {
        res = res_base + 1;
    }
    else
    {
        res = res_base + 2;
    }

    //@ assert ((res) <= 2 * ((n) / 11) + 2);
    //@ assert ((res) >= 2 * ((n) / 11));

    return res;
}
