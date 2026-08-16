#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b, integer c, integer k) =
        0 <= a <= 1000000000 &&
        0 <= b <= 1000000000 &&
        0 <= c <= 1000000000 &&
        1 <= k <= 1000000000 &&
        a + b + c >= k;

    logic integer compute_sum(integer a, integer b, integer c, integer k) =
        a <= k ?
            (b <= k - a ?
                (c <= k - a - b ? a - c : a - (k - a - b))
                : a)
            : k;

    lemma sum_lower_bound:
        \forall integer a, b, c, k;
            valid_inputs(a, b, c, k) ==> compute_sum(a, b, c, k) >= -c;

    lemma sum_upper_bound:
        \forall integer a, b, c, k;
            valid_inputs(a, b, c, k) ==> compute_sum(a, b, c, k) <= a;
*/

/*@
    requires valid_inputs(a, b, c, k);
    ensures \result >= -c;
    ensures \result <= a;
    ensures \result == compute_sum(a, b, c, k);
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t sum = 0;
    int64_t remaining_k = k;

    //@ assert valid_inputs(a, b, c, k);
    
    if (a <= remaining_k)
    {
        sum += a;
        remaining_k -= a;
    }
    else
    {
        //@ assert compute_sum(a, b, c, k) == k;
        return k;
    }

    //@ assert sum == a;
    //@ assert remaining_k == k - a;
    
    if (b <= remaining_k)
    {
        remaining_k -= b;
    }
    else
    {
        remaining_k = 0;
    }

    //@ assert remaining_k == (b <= k - a ? k - a - b : 0);
    
    if (c <= remaining_k)
    {
        sum -= c;
    }
    else
    {
        sum -= remaining_k;
    }

    //@ assert sum == compute_sum(a, b, c, k);
    //@ assert sum >= -c;
    
    return sum;
}
