#include <stdint.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 10 && 1 <= b <= 10;
    
    logic integer safe_sum(integer a, integer b) = a + b;
    
    lemma sum_bounds:
        \forall integer a, b; valid_range(a, b) ==> 2 <= safe_sum(a, b) <= 20;
*/

/*@
    requires valid_range(a, b);
    ensures \result == safe_sum(a, b);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    //@ assert valid_range(a, b);
    //@ assert 2 <= safe_sum(a, b) <= 20;
    
    int32_t result;
    result = a + b;
    
    //@ assert result == safe_sum(a, b);
    return result;
}
