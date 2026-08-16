#include <stdint.h>

/*@
    predicate valid_input(integer n, integer m) =
        1 <= n && n <= 1000000000000 &&
        1 <= m && m <= 1000000000000;

    logic integer compute_ans(integer n, integer m) =
        (n * 2 <= m) ? (n + (m - n * 2) / 4) : (m / 2);

    lemma ans_bound: \forall integer n, m;
        valid_input(n, m) ==> compute_ans(n, m) <= n + m;
*/

/*@
    requires valid_input(n, m);
    ensures \result <= n + m;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t ans;

    //@ assert valid_input(n, m);

    if (n * 2 <= m)
    {
        ans = n + (m - n * 2) / 4;
        //@ assert n * 2 <= m ==> ans <= n + m;
    }
    else
    {
        ans = m / 2;
        //@ assert n * 2 > m ==> ans <= n + m;
    }

    //@ assert ans <= n + m;
    return ans;
}
