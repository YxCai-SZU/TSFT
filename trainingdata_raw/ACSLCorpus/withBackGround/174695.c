#include <stdint.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    
    logic integer compute_result(integer r) = 3 * r * r;
    
    lemma result_non_negative: \forall integer r; is_valid_range(r) ==> compute_result(r) >= 0;
    lemma result_bound: \forall integer r; is_valid_range(r) ==> compute_result(r) <= 30000;
*/

/*@
    requires is_valid_range(r);
    ensures \result == compute_result(r);
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at top of scope
    int32_t ans;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r <= 300;
    //@ assert 3 * r * r <= 30000;
    
    ans = 3 * r * r;
    
    //@ assert ans == compute_result(r);
    //@ assert ans >= 0;
    
    return ans;
}
