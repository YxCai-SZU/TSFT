#include <stdint.h>

/*@
    predicate r_in_range(integer r) = 1 <= r <= 100;
    
    logic integer target_value(integer r) = 3 * r * r;
    
    lemma bounds_lemma: 
        \forall integer r; r_in_range(r) ==> 0 <= target_value(r) <= 3 * 100 * 100;
*/

/*@
    requires r_in_range(r);
    ensures \result == target_value(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t ans;
    
    //@ assert 1 <= r <= 100;
    //@ assert 3 * r <= 3 * 100;
    //@ assert 0 <= 3 * r * r;
    
    ans = 0;
    //@ assert ans == 0;
    
    ans = 3 * r * r;
    
    return ans;
}
