#include <stdint.h>

/*@
    predicate bounds(integer n, integer a) =
        1 <= n <= 100 &&
        0 <= a <= n * n;

    logic integer compute_result(integer n, integer a) =
        n * n - a;

    lemma multiplication_bounds:
        \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
*/

/*@
    requires bounds(n, a);
    ensures \result == compute_result(n, a);
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t a)
{
    // Variable declarations at scope top
    int32_t nn;
    int32_t result;

    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= a && a <= n * n;
    //@ assert n * n <= 10000;

    nn = n * n;
    result = nn - a;
    
    //@ assert result == n * n - a;
    return result;
}
