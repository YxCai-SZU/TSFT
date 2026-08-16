#include <stdint.h>

/*@
    predicate in_range_int32(integer v) = -1000000000 <= v && v <= 1000000000;
    predicate in_range_int64(integer v) = 1 <= v && v <= 100000000000000000;
    logic integer compute_result(integer a, integer b, integer c, integer k) =
        (k >= a ? 
            (k - a >= b ? 
                (k - a - b >= c ? a - c : a - (k - a - b)) 
                : (k >= a ? a : k) - (k >= a ? k - a : 0))
            : k);
*/

/*@
    requires
        1 <= a && a <= 1000000000 &&
        1 <= b && b <= 1000000000 &&
        1 <= c && c <= 1000000000 &&
        1 <= k && k <= 100000000000000000;
    ensures
        -1000000000 <= \result && \result <= 1000000000;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int64_t k)
{
    int64_t k_mut;
    int32_t res;

    k_mut = k;
    res = 0;

    if (k_mut >= (int64_t)a)
    {
        res += a;
        k_mut -= (int64_t)a;
    }
    else
    {
        res += (int32_t)k_mut;
        k_mut = 0;
    }

    //@ assert in_range_int32(res);

    if (k_mut >= (int64_t)b)
    {
        k_mut -= (int64_t)b;
    }
    else
    {
        res -= (int32_t)k_mut;
        k_mut = 0;
    }

    //@ assert in_range_int32(res);

    if (k_mut >= (int64_t)c)
    {
        res -= c;
        k_mut -= (int64_t)c;
    }
    else
    {
        res -= (int32_t)k_mut;
        k_mut = 0;
    }

    //@ assert in_range_int32(res);
    return res;
}
