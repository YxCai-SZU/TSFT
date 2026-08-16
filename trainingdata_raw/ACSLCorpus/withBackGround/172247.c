#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && 0 <= b && 0 <= c &&
        1 <= k && k <= a + b + c &&
        a + b + c <= 2000000000;

    logic integer compute_result(integer a, integer b, integer c, integer k) =
        k <= a ? k :
        k <= a + b ? a :
        a - (k - a - b);

    lemma result_bounds:
        \forall integer a, b, c, k;
        valid_params(a, b, c, k) ==>
        compute_result(a, b, c, k) <= a &&
        compute_result(a, b, c, k) >= -c;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures \result <= a;
    ensures \result >= -c;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t ans = 0;
    int32_t rest = k;

    //@ assert valid_params(a, b, c, k);

    if (rest > a)
    {
        ans += a;
        rest -= a;
        //@ assert ans == a && rest == k - a;
    }
    else
    {
        ans += rest;
        //@ assert ans == k && ans <= a;
        return ans;
    }

    if (rest > b)
    {
        rest -= b;
        //@ assert rest == k - a - b;
    }
    else
    {
        //@ assert ans == a && rest <= b;
        return ans;
    }

    ans -= rest;
    //@ assert ans == a - (k - a - b);

    //@ assert ans >= -c;
    return ans;
}
