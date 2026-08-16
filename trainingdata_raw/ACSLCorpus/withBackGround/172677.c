#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && 1 <= m && n <= 1000000000000 && m <= 1000000000000;

    logic integer compute_bound(integer n, integer m) = n + m / 2;

    lemma res_bounds:
        \forall integer n, m, res;
        valid_params(n, m) &&
        (n < m / 2 ==> res == n + (m - 2 * n) / 4) &&
        (n >= m / 2 ==> res == m / 2) ==>
        res <= compute_bound(n, m) && res >= m / 4;
*/

/*@
    requires valid_params(n, m);
    ensures \result <= n + m / 2;
    ensures \result >= m / 4;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t m_local = m;
    uint64_t res = 0;

    //@ assert valid_params(n, m_local);

    if (n < m_local / 2)
    {
        //@ assert n < m_local / 2;
        res += n;
        m_local -= 2 * n;
        res += m_local / 4;
        //@ assert res == n + (m - 2 * n) / 4;
    }
    else
    {
        //@ assert n >= m_local / 2;
        res = m_local / 2;
        //@ assert res == m / 2;
    }

    //@ assert res >= m_local / 4;
    //@ assert res <= n + m / 2;

    return res;
}
