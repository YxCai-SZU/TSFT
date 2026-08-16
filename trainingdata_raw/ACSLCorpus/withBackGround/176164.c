#include <stddef.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && 1 <= m && n <= 1000000000000 && m <= 1000000000000;

    logic integer func_result(integer n, integer m) =
        n >= m / 2 ? m / 2 : n + (m - 2 * n) / 4;

    lemma result_bounds: \forall integer n, m;
        valid_params(n, m) ==>
            func_result(n, m) <= n + m / 2 &&
            func_result(n, m) >= m / 4;
*/

/*@
    requires valid_params(n, m);
    ensures \result == func_result(n, m);
    ensures \result <= n + m / 2;
    ensures \result >= m / 4;
*/
size_t func(size_t n, size_t m)
{
    size_t result;
    size_t l;
    size_t l2;

    //@ assert valid_params(n, m);
    
    if (n >= m / 2)
    {
        result = m / 2;
        //@ assert result == m / 2;
    }
    else
    {
        l = m - 2 * n;
        l2 = l / 4;
        //@ assert l2 == (m - 2 * n) / 4;
        result = n + l2;
        //@ assert result == n + (m - 2 * n) / 4;
    }

    //@ assert result == func_result(n, m);
    //@ assert result <= n + m / 2;
    //@ assert result >= m / 4;
    
    return result;
}
