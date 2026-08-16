#include <limits.h>

/*@
    predicate valid_params(integer n, integer x, integer t) =
        1 <= n && n <= 1000 &&
        1 <= x && x <= 1000 &&
        1 <= t && t <= 1000;

    logic integer compute_ans(integer n, integer x, integer t) =
        n >= x ? t + (n - x) : n + t;

    lemma ans_bounds: \forall integer n, x, t;
        valid_params(n, x, t) ==>
        compute_ans(n, x, t) >= 0 &&
        compute_ans(n, x, t) <= n + t;
*/

/*@
    requires valid_params(n, x, t);
    ensures \result >= 0;
    ensures \result <= n + t;
    assigns \nothing;
*/
int func(int n, int x, int t)
{
    int ans;
    //@ assert 1 <= n && n <= 1000;
    //@ assert 1 <= x && x <= 1000;
    //@ assert 1 <= t && t <= 1000;

    if (n >= x)
    {
        //@ assert n - x <= 1000;
        //@ assert t + (n - x) <= 2000;
        ans = t + (n - x);
    }
    else
    {
        //@ assert n + t <= 2000;
        ans = n + t;
    }

    //@ assert ans >= 0;
    //@ assert ans <= n + t;
    return ans;
}
