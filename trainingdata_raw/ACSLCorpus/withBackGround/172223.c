#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 179;
    
    logic integer compute_result(integer x) = 360 - x * 2;
    
    lemma arithmetic_bounds:
        \forall integer x; valid_range(x) ==> 2 <= x * 2 <= 358;
    
    lemma result_nonnegative:
        \forall integer x; valid_range(x) ==> compute_result(x) >= 0;
*/

/*@
    requires valid_range(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
int32_t func(int32_t x)
{
    // Variable declarations at scope top
    int32_t ret;
    
    //@ assert valid_range(x);
    
    //@ assert 2 <= x * 2 <= 358;
    
    //@ assert 360 - x * 2 >= 0;
    
    ret = 360 - x * 2;
    
    //@ assert ret == compute_result(x);
    
    return ret;
}
