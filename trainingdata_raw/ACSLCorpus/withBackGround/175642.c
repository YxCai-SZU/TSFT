#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer func_spec(integer n) = n * 800 - (n / 15) * 200;
    
    lemma no_overflow: \forall integer n; valid_n(n) ==> n * 800 <= 100 * 800;
*/

/*@
    requires valid_n(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    uint64_t x;
    
    //@ assert valid_n(n);
    //@ assert n * 800 <= 100 * 800;
    
    x = n * 800 - (n / 15) * 200;
    
    //@ assert x == func_spec(n);
    
    return x;
}
