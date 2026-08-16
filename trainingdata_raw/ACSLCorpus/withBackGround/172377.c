#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n <= 100 &&
        0 <= a <= n * n;

    lemma n_squared_bound: \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
*/

/*@
    requires valid_params(n, a);
    ensures \result == n * n - a;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a)
{
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    //@ assert n * n <= 10000;
    
    return n * n - a;
}
