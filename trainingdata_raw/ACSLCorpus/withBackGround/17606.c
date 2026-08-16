#include <stdint.h>

/*@
    predicate bounds(integer n) = 1 <= n && n <= 100;
    logic integer result(integer n) = 3 * n * n;
    lemma result_bounds: \forall integer n; bounds(n) ==> result(n) <= 30000;
*/

/*@
    requires bounds(n);
    ensures \result == result(n);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t res;
    
    //@ assert bounds(n);
    //@ assert 3 * n <= 300;
    //@ assert result(n) <= 30000;
    
    res = 3 * n * n;
    
    //@ assert res == result(n);
    return res;
}
