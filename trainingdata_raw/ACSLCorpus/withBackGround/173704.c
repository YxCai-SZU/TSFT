#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;

    logic integer func_result(integer n, integer m) =
        (2*m + 1 <= n) ? (n - 2*m) : (m - 1);

    lemma result_bounds_1:
        \forall integer n, m;
        valid_range(n, m) && 2*m + 1 <= n ==>
        0 <= n - 2*m <= 20;

    lemma result_bounds_2:
        \forall integer n, m;
        valid_range(n, m) && 2*m + 1 > n ==>
        0 <= m - 1 <= 20;
*/

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures \result == func_result(n, m);
*/
int func(int n, int m)
{
    int result;
    
    //@ assert valid_range(n, m);
    
    if (2*m + 1 <= n) {
        //@ assert 2*m + 1 <= n;
        //@ assert 0 <= n - 2*m <= 20;
        result = n - 2*m;
    } else {
        //@ assert 2*m + 1 > n;
        //@ assert 0 <= m - 1 <= 20;
        result = m - 1;
    }
    
    //@ assert result == func_result(n, m);
    return result;
}
