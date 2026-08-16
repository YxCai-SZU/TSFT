#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= 100;

    logic integer compute_result(integer n, integer m) =
        n - 2 * m > 0 ? n - 2 * m : 0;

    lemma result_nonnegative:
        \forall integer n, m;
        valid_range(n, m) ==> compute_result(n, m) >= 0;

    lemma result_cases:
        \forall integer n, m;
        valid_range(n, m) ==> 
        (compute_result(n, m) == n - 2 * m || compute_result(n, m) == 0);
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result >= 0;
    ensures \result == n - 2 * m || \result == 0;
    assigns \nothing;
*/
int func(int n, int m)
{
    int result;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= 100;
    //@ assert 2 * m <= 200;
    //@ assert n - 2 * m >= -199;
    
    if (n - 2 * m > 0)
    {
        result = n - 2 * m;
    }
    else
    {
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == n - 2 * m || result == 0;
    
    return result;
}
