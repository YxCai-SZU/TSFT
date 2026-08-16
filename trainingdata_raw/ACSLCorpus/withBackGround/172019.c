#include <limits.h>

/*@
    predicate is_valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c &&
        1 <= k && k <= a + b + c && k <= 2000000000;

    logic integer compute_ans(integer a, integer b, integer c, integer k) =
        (a >= k) ? k : 
        (a + b >= k) ? a : 
        a - (k - a - b);

    lemma ans_bounds: \forall integer a, b, c, k;
        is_valid_params(a, b, c, k) ==> 
            -k <= compute_ans(a, b, c, k) <= k;
*/

/*@
    requires is_valid_params(a, b, c, k);
    ensures -k <= \result <= k;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans = 0;
    int rst = k;

    //@ assert rst == k;
    if (a >= rst)
    {
        ans += rst;
        rst = 0;
    }
    else
    {
        ans += a;
        rst -= a;
    }

    //@ assert ans >= -k && ans <= k;
    if (b >= rst)
    {
        rst = 0;
    }
    else
    {
        rst -= b;
    }

    //@ assert ans >= -k && ans <= k;
    //@ assert rst >= 0 && rst <= k;
    ans -= rst;

    //@ assert ans >= -k && ans <= k;
    return ans;
}
