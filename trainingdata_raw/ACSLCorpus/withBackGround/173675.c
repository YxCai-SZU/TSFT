#include <limits.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 1000000000 &&
        1 <= b && b <= 1000000000 &&
        1 <= c && c <= 1000000000 &&
        1 <= k && k <= 1000000000 &&
        a + b + c >= k;

    logic integer final_sum(integer a, integer b, integer c, integer k) =
        k >= a ?
            (k - a >= b ?
                (k - a - b >= c ? a - c : a - (k - a - b))
                : a)
            : k;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result >= -c && \result <= a;
    ensures \result <= k;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int k_remaining;
    int sum;

    k_remaining = k;
    sum = 0;

    if (k_remaining >= a)
    {
        sum += a;
        k_remaining -= a;
    }
    else
    {
        sum += k_remaining;
        k_remaining = 0;
    }

    if (k_remaining > 0)
    {
        if (k_remaining >= b)
        {
            k_remaining -= b;
        }
        else
        {
            k_remaining = 0;
        }
    }

    //@ assert sum >= -c && sum <= a;
    //@ assert k_remaining <= c;

    if (k_remaining > 0)
    {
        sum -= k_remaining;
    }

    //@ assert sum >= -c && sum <= a;
    //@ assert sum <= k;

    return sum;
}
