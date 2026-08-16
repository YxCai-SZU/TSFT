#include <stdint.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 1000000000000 && 1 <= m <= 1000000000000;

    logic integer max_result(integer n, integer m) = n + m / 4;
*/

/*@
    requires valid_range(n, m);
    ensures \result <= max_result(n, m);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t result = 0;
    uint64_t n_local = n;
    uint64_t m_local = m;

    //@ assert valid_range(n_local, m_local);

    if (n_local < m_local / 4)
    {
        result += n_local;
        m_local -= 4 * n_local;
        result += m_local / 4;
        //@ assert result <= max_result(n, m);
    }
    else
    {
        result += m_local / 4;
        //@ assert result <= max_result(n, m);
    }

    //@ assert result <= max_result(n, m);
    return result;
}
