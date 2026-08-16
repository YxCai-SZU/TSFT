#include <stdint.h>

/*@
    predicate valid_input(integer n, integer m) =
        1 <= n && 1 <= m && n <= 1000000000000 && m <= 1000000000000;

    logic integer func_result(integer n, integer m) =
        (2 * n < m) ? n + (m - 2 * n) / 4 : m / 2;

    lemma result_bounds: \forall integer n, m;
        valid_input(n, m) ==> 0 <= func_result(n, m) && func_result(n, m) <= n + m;
*/

/*@
    requires valid_input(n, m);
    ensures \result == func_result(n, m);
    ensures 0 <= \result && \result <= n + m;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert 1 <= n && n <= 1000000000000;
    //@ assert 1 <= m && m <= 1000000000000;

    if (2 * n < m)
    {
        //@ assert 2 * n < m;
        result = n + (m - 2 * n) / 4;
    }
    else
    {
        //@ assert m / 2 <= 1000000000000;
        result = m / 2;
    }

    //@ assert result == func_result(n, m);
    //@ assert 0 <= result && result <= n + m;
    return result;
}
