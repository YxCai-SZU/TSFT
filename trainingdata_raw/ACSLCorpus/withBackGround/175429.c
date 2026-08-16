#include <stddef.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 20;

    logic integer compute_result(integer t, integer a, integer b) = 
        (t / a) * b;

    lemma result_bounds:
        \forall integer t, a, b;
        valid_range(a) && valid_range(b) && valid_range(t) ==> 
        compute_result(t, a, b) <= 400;
*/

/*@
    requires valid_range(a) && valid_range(b) && valid_range(t);
    ensures \result == compute_result(t, a, b);
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t t)
{
    // Variable declarations at scope top
    size_t ans;

    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(t);
    
    //@ assert compute_result(t, a, b) <= 400;
    
    ans = (t / a) * b;
    
    //@ assert ans == compute_result(t, a, b);
    
    return ans;
}
