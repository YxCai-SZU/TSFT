#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_ans(integer a, integer b) =
        a - 2 * b;

    lemma ans_nonnegative:
        \forall integer a, b, ans;
        valid_range(a, b) && ans == compute_ans(a, b) && ans > 0 ==>
        ans >= 0;
*/

/*@
    requires valid_range(a, b);
    ensures \result >= 0;
    ensures \result == a - 2 * b || \result == 0;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t ans;
    int64_t res;

    ans = a - 2 * b;

    //@ assert ans == a - 2 * b;

    if (ans > 0)
    {
        //@ assert ans >= 0;
        res = ans;
    }
    else
    {
        //@ assert 0 >= 0;
        res = 0;
    }

    return res;
}
