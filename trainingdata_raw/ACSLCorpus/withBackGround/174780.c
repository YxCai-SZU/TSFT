#include <stddef.h>

/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    logic integer func_spec(integer r) = 3 * r * r;
    lemma func_bound: \forall integer r; r_in_range(r) ==> func_spec(r) <= 30000;
*/

/*@
    requires r_in_range(r);
    ensures \result == func_spec(r);
    assigns \nothing;
*/
size_t func(size_t r)
{
    // Variable declarations at top of scope
    size_t ans;

    //@ assert r >= 1 && r <= 100;
    
    //@ assert 3 * r * r <= 3 * 100 * 100;
    
    ans = 3 * r * r;
    
    //@ assert ans <= 30000;
    
    return ans;
}
