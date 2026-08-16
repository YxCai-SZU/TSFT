#include <limits.h>

/*@
    predicate max_val_is_r(integer r) = r >= 0;
    predicate max_val_is_zero(integer r) = r < 0;

    logic integer compute_max_val(integer r) = (r >= 0) ? r : 0;

    logic integer compute_ans(integer n, integer r) =
        compute_max_val(r) + ((n >= 10) ? 0 : 100 * (10 - n));

    lemma ans_correctness:
        \forall integer n, r;
        1 <= n <= 100 && 0 <= r <= 4111 ==>
        compute_ans(n, r) == r + ((n >= 10) ? 0 : 100 * (10 - n));
*/

/*@
    requires 1 <= n <= 100;
    requires 0 <= r <= 4111;
    ensures \result == r + ((n >= 10) ? 0 : 100 * (10 - n));
*/
int func(int n, int r)
{
    int max_val;
    int ans;

    //@ assert 0 <= r <= 4111;
    if (0 > r)
    {
        max_val = 0;
        //@ assert max_val == 0;
    }
    else
    {
        max_val = r;
        //@ assert max_val == r;
    }

    //@ assert max_val == ((0 > r) ? 0 : r);
    //@ assert max_val == compute_max_val(r);

    if (n >= 10)
    {
        ans = max_val + 0;
        //@ assert ans == max_val;
    }
    else
    {
        ans = max_val + 100 * (10 - n);
        //@ assert ans == max_val + 100 * (10 - n);
    }

    //@ assert ans == compute_ans(n, r);
    //@ assert ans == r + ((n >= 10) ? 0 : 100 * (10 - n));
    return ans;
}
