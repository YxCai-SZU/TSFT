#include <stdint.h>

/*@
    predicate is_in_range(integer n) = 1 <= n <= 100;
    
    logic integer compute_result(integer n, integer m) = n - 2 * m;
    
    lemma result_nonnegative:
        \forall integer n, m;
        is_in_range(n) && is_in_range(m) && compute_result(n, m) >= 0 ==>
        compute_result(n, m) >= 0;
    
    lemma result_zero_or_diff:
        \forall integer n, m, res;
        is_in_range(n) && is_in_range(m) &&
        (res == 0 || res == compute_result(n, m)) ==>
        (res == n - 2 * m || res == 0);
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result >= 0;
    ensures \result == n - 2 * m || \result == 0;
*/
int64_t func(int64_t n, int64_t m)
{
    int64_t result;
    
    result = n - 2 * m;
    
    if (result < 0)
    {
        //@ assert result < 0;
        return 0;
    }
    else
    {
        //@ assert result >= 0;
        return result;
    }
}
