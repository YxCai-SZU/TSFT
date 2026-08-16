#include <stdint.h>

/*@
    predicate valid_input(integer n) = 3 <= n && n <= 100;
    
    logic integer func_spec(integer n) = 180 * n - 360;
    
    lemma func_lemma: \forall integer n; valid_input(n) ==> func_spec(n) == 180 * n - 360;
*/

/*@
    requires valid_input(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert 180 * 3 <= 180 * n;
    //@ assert 180 * n <= 180 * 100;
    
    result = 180 * n - 360;
    
    //@ assert result == func_spec(n);
    return result;
}
