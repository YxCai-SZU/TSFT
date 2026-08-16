#include <stdint.h>

/*@
    predicate valid_input(integer n, integer m) =
        1 <= n && n <= 1000000000000 &&
        1 <= m && m <= 1000000000000;

    logic integer func_result(integer n, integer m) =
        (2 * n < m) ? (n + (m - 2 * n) / 4) : (m / 2);

    lemma func_bound: \forall integer n, m;
        valid_input(n, m) ==> func_result(n, m) <= n + m;
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

    if (2 * n < m)
    {
        //@ assert 2 * n < m;
        ans = n + (m - 2 * n) / 4;
        //@ assert ans == n + (m - 2 * n) / 4;
    }
    else
    {
        ans = m / 2;
        //@ assert ans == m / 2;
    }

    //@ assert ans <= n + m;
    return ans;
}
