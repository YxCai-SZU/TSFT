#include <limits.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        1 <= a <= 100 &&
        1 <= b <= 100 &&
        1 <= c <= 100 &&
        1 <= k <= 100 &&
        a + b + c >= k;
*/

/*@
    logic integer min(integer x, integer y) =
        x < y ? x : y;
*/

/*@
    lemma ans_lower_bound:
        \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==>
        \let ans = min(a, k) - min(c, k - min(a, k) - min(b, k - min(a, k)));
        ans >= -k;
*/

/*@
    lemma ans_upper_bound:
        \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==>
        \let ans = min(a, k) - min(c, k - min(a, k) - min(b, k - min(a, k)));
        ans <= k;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result >= -k;
    ensures \result <= k;
    assigns \nothing;
*/
long long func(long long a, long long b, long long c, long long k)
{
    long long ans;
    long long rst;
    long long min_val;

    ans = 0;
    rst = k;

    //@ assert valid_params(a, b, c, k);

    min_val = a < rst ? a : rst;
    ans += min_val;
    rst -= min_val;

    //@ assert ans >= 0 && ans <= k;

    min_val = b < rst ? b : rst;
    rst -= min_val;

    //@ assert ans >= 0 && ans <= k;

    min_val = c < rst ? c : rst;
    ans -= min_val;

    //@ assert ans >= -k && ans <= k;

    return ans;
}
