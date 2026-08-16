#include <stdint.h>

/*@
    predicate valid_n(integer n) = 1 <= n && n <= 1000000;
    
    logic integer func_spec(integer n) = (n - 1) / 2;
    
    lemma func_lemma:
        \forall integer n; valid_n(n) ==> func_spec(n) == (n - 1) / 2;
*/

/*@
    requires valid_n(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t ans;
    
    //@ assert valid_n(n);
    
    ans = (n - 1) / 2;
    
    //@ assert ans == func_spec(n);
    
    return ans;
}
