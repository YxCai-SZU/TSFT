#include <stdint.h>

/*@
    predicate bounds(integer n, integer r) =
        1 <= n <= 100 && 0 <= r <= 4111;

    logic integer compute(integer n, integer r) =
        n >= 10 ? r : r + 100 * (10 - n);

    lemma compute_bounds:
        \forall integer n, r;
            bounds(n, r) ==> 0 <= compute(n, r) <= 4111 + 100 * 9;
*/

/*@
    requires bounds(n, r);
    ensures \result == r || \result == r + 100 * (10 - n);
    ensures 0 <= \result <= 4111 + 100 * 9;
*/
uint32_t func(uint32_t n, uint32_t r)
{
    // Variable declarations at scope top
    uint32_t ans;

    //@ assert bounds(n, r);

    if (n >= 10)
    {
        ans = r;
        //@ assert ans == r;
    }
    else
    {
        ans = r + 100 * (10 - n);
        //@ assert ans == r + 100 * (10 - n);
    }

    //@ assert ans == compute(n, r);
    return ans;
}
