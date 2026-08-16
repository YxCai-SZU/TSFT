#include <stdint.h>

/*@
    predicate bounds(integer n, integer a) =
        1 <= n <= 100 && 0 <= a <= n * n;
    
    logic integer result(integer n, integer a) = n * n - a;
    
    lemma n_squared_bound: \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
*/

/*@
    requires bounds(n, a);
    ensures \result == result(n, a);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a)
{
    // Variable declarations at top
    uint32_t res;
    
    //@ assert n <= 100;
    //@ assert a <= n * n;
    //@ assert n * n <= 10000;
    
    res = n * n - a;
    return res;
}
