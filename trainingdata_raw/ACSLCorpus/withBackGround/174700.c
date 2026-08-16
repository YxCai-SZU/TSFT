#include <stddef.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    logic integer result_value(integer r) = 3 * r * r;
    lemma no_overflow: \forall integer r; is_valid_range(r) ==> 3 * r * r <= 30000;
*/

/*@
    requires is_valid_range(r);
    ensures \result == result_value(r);
    assigns \nothing;
*/
size_t func(size_t r)
{
    // Variable declarations at top of scope
    size_t pi_approx = 3;
    size_t result;

    //@ assert pi_approx * r <= 300;
    
    //@ assert 3 * r * r <= 30000;
    
    //@ assert pi_approx * r * r <= 30000;
    
    result = pi_approx * r * r;
    
    //@ assert result == result_value(r);
    
    return result;
}
