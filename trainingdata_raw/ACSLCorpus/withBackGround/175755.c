#include <stdint.h>

/*@
    predicate valid_params(integer n, integer a) =
        1 <= n <= 100 && 0 <= a <= n * n;
    
    logic integer square(integer n) = n * n;
    
    lemma square_bounds:
        \forall integer n; 1 <= n <= 100 ==> n * n <= 10000;
*/

/*@
    requires valid_params(n, a);
    ensures \result == n * n - a;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    // Precondition verification
    //@ assert 1 <= n <= 100;
    //@ assert 0 <= a <= n * n;
    
    // Mathematical property
    //@ assert n * n >= a;
    
    // Lemma application
    //@ assert n * n <= 10000;
    
    result = n * n - a;
    
    // Postcondition verification
    //@ assert result == n * n - a;
    
    return result;
}
