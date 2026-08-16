#include <limits.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    logic integer func_result(integer n, integer m) =
        n == 1 ? 1 : m * (n - 1) + 1;

    lemma result_bounds: \forall integer n, m;
        valid_params(n, m) ==> 1 <= func_result(n, m) <= m * 100 + 1;
*/

/*@
    requires valid_params(n, m);
    ensures \result == func_result(n, m);
    ensures 1 <= \result <= m * 100 + 1;
*/
long func(long n, long m)
{
    // Variable declarations at top
    long result;

    if (n == 1)
    {
        result = 1;
    }
    else
    {
        //@ assert 1 <= n && n <= 100;
        //@ assert 1 <= m && m <= 100;
        //@ assert m * (n - 1) <= 100 * 99;
        result = m * (n - 1) + 1;
    }

    return result;
}
