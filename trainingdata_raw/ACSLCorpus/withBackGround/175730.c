#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c &&
        1 <= k && k <= a + b + c &&
        a + b + c <= 2000000000;

    logic integer compute_ans(integer a, integer b, integer c, integer k) =
        k <= a ? k :
        k <= a + b ? a :
        a - (k - a - b);

    lemma ans_lower_bound:
        \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==>
        compute_ans(a, b, c, k) >= -c;

    lemma ans_upper_bound:
        \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==>
        compute_ans(a, b, c, k) <= a;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result >= -c;
    ensures \result <= a;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t ans = 0;
    int32_t rst = k;

    //@ assert valid_params(a, b, c, k);

    if (a >= rst)
    {
        ans += rst;
        //@ assert ans >= -c;
        //@ assert ans <= a;
        return ans;
    }
    else
    {
        ans += a;
        rst -= a;
    }

    //@ assert ans <= a;
    //@ assert ans >= -c;

    if (b >= rst)
    {
        //@ assert ans >= -c;
        //@ assert ans <= a;
        return ans;
    }
    else
    {
        rst -= b;
    }

    //@ assert rst == k - a - b;
    //@ assert rst >= 0;
    //@ assert rst <= c;

    ans -= rst;

    //@ assert ans >= -c;
    //@ assert ans <= a;

    return ans;
}
