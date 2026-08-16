#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (k) && (k) <= 1000000000000);
    ensures \result >= 0;
    ensures \result <= k / 2;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    uint64_t res;
    uint64_t remainder;
    uint64_t d;

    remainder = n % k;

    if (remainder <= k / 2)
    {
        res = remainder;
    }
    else
    {
        d = k - remainder;
        //@ assert d <= k / 2;
        res = d;
    }

    return res;
}
