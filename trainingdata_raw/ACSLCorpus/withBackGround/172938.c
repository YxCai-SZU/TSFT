#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c, integer k) =
        1 <= a && a <= 1000000000 &&
        1 <= b && b <= 1000000000 &&
        1 <= c && c <= 1000000000 &&
        1 <= k && k <= 1000000000 &&
        a + b + c >= k;

    logic integer compute_ans(integer a, integer b, integer c, integer k) =
        k <= a ? k : a - (k - a - b > 0 ? k - a - b : 0);

    lemma ans_lower_bound:
        \forall integer a, b, c, k;
        valid_input(a, b, c, k) ==> compute_ans(a, b, c, k) >= -c;

    lemma ans_upper_bound:
        \forall integer a, b, c, k;
        valid_input(a, b, c, k) ==> compute_ans(a, b, c, k) <= a;
*/

/*@
    requires valid_input(a, b, c, k);
    ensures \result >= -c;
    ensures \result <= a;
    ensures \result == compute_ans(a, b, c, k);
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans = 0;
    int64_t rst = k;

    //@ assert valid_input(a, b, c, k);

    if (a >= rst)
    {
        ans += rst;
        rst -= rst;
        //@ assert ans == k && rst == 0;
    }
    else
    {
        ans += a;
        rst -= a;
        //@ assert ans == a && rst == k - a;
    }

    //@ assert ans >= -c;
    //@ assert ans <= a;

    if (b >= rst)
    {
        rst -= rst;
        //@ assert rst == 0;
    }
    else
    {
        rst -= b;
        //@ assert rst == k - a - b;
    }

    //@ assert ans >= -c;
    //@ assert ans <= a;

    ans -= rst;

    //@ assert ans >= -c;
    //@ assert ans <= a;

    return ans;
}
