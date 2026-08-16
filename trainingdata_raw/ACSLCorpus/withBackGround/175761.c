#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n * n;

    logic integer compute_result(integer n, integer m) =
        n * n - m;

    lemma n_squared_range:
        \forall integer n; 1 <= n <= 100 ==> 1 <= n * n <= 10000;
*/

/*@
    requires valid_params(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int nn;
    int result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n * n;
    //@ assert 1 <= n * n && n * n <= 10000;

    nn = n * n;
    result = nn - m;
    
    return result;
}
