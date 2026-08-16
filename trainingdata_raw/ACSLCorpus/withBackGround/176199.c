#include <stdint.h>

/*@
    predicate valid_params(integer n, integer r) =
        1 <= n && n <= 100 &&
        0 <= r && r <= 4111;

    logic integer compute_ans(integer n, integer r) =
        n >= 10 ? r : r + 100 * (10 - n);

    lemma ans_property:
        \forall integer n, r;
        valid_params(n, r) ==>
        compute_ans(n, r) == (n >= 10 ? r : r + 100 * (10 - n));
*/

/*@
    requires valid_params(n, r);
    ensures \result == compute_ans(n, r);
    ensures n >= 10 ==> \result == r;
    ensures n < 10 ==> \result == r + 100 * (10 - n);
*/
uint64_t func(uint64_t n, uint64_t r)
{
    uint64_t ans;

    //@ assert valid_params(n, r);
    
    if (n >= 10)
    {
        ans = r;
    }
    else
    {
        //@ assert 100 * (10 - n) <= 100 * 10;
        ans = r + 100 * (10 - n);
    }

    //@ assert ans == compute_ans(n, r);
    return ans;
}
