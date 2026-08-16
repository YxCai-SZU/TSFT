#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100 &&
        1 <= k && k <= 3;

    logic integer min_k_a(integer k, integer a) =
        k <= a ? k : a;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result <= a + b + c;
    ensures \result >= min_k_a(k, a);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    uint32_t k_remaining;
    uint32_t total;

    k_remaining = k;
    total = 0;

    if (a >= k_remaining)
    {
        total += k_remaining;
        k_remaining = 0;
    }
    else
    {
        total += a;
        k_remaining -= a;
    }

    if (k_remaining != 0)
    {
        if (b >= k_remaining)
        {
            k_remaining = 0;
        }
        else
        {
            k_remaining -= b;
        }
    }

    if (k_remaining != 0)
    {
        if (c >= k_remaining)
        {
            total += k_remaining;
            k_remaining = 0;
        }
        else
        {
            total += c;
            k_remaining -= c;
        }
    }

    //@ assert total <= a + b + c;
    //@ assert total >= min_k_a(k, a);

    return total;
}
