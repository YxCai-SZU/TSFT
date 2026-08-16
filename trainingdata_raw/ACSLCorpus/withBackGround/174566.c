#include <limits.h>

/*@
    predicate valid_params(integer n, integer k, integer x, integer y) =
        1 <= n <= 10000 &&
        1 <= k <= 10000 &&
        1 <= y < x <= 10000;

    logic integer compute_res(integer n, integer k, integer x, integer y) =
        n <= k ? x * n : x * k + (n - k) * y;

    lemma product_bound1:
        \forall integer n, integer x;
            1 <= n <= 10000 && 1 <= x <= 10000 ==> x * n <= 100000000;

    lemma product_bound2:
        \forall integer n, integer k, integer x, integer y;
            valid_params(n, k, x, y) && n > k ==> x * k <= 100000000;

    lemma product_bound3:
        \forall integer n, integer k, integer x, integer y;
            valid_params(n, k, x, y) && n > k ==> (n - k) * y <= 99990000;

    lemma sum_bound:
        \forall integer n, integer k, integer x, integer y;
            valid_params(n, k, x, y) && n > k ==> 
                x * k + (n - k) * y <= 199990000;
*/

/*@
    requires valid_params(n, k, x, y);
    ensures \result == compute_res(n, k, x, y);
    assigns \nothing;
*/
int func(int n, int k, int x, int y)
{
    int ans;

    //@ assert 1 <= n <= 10000;
    //@ assert 1 <= k <= 10000;
    //@ assert 1 <= y < x <= 10000;

    if (n <= k)
    {
        //@ assert x > 0 && x <= 10000 && n >= 1 && n <= 10000;
        //@ assert x * n <= 100000000;
        ans = x * n;
        return ans;
    }

    //@ assert x > 0 && x <= 10000 && k >= 1 && k <= 10000;
    //@ assert n - k >= 0 && n - k <= 9999 && y >= 1 && y < x;
    //@ assert x * k <= 100000000;
    //@ assert (n - k) * y <= 99990000;
    ans = x * k + (n - k) * y;
    return ans;
}
