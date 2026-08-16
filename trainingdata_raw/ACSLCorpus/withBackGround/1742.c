#include <stdbool.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;

    logic integer compute_result(integer r, integer pi) = r * 2 * pi;

    lemma pi_value: \forall integer r, integer pi; pi == 3 ==> compute_result(r, pi) == 2 * r * 3;
*/

/*@
    requires valid_range(r);
    ensures \result == 2 * r * 3;
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int pi;
    int result;

    pi = 3;
    
    //@ assert pi == 3;
    
    result = r * 2 * pi;
    
    //@ assert result == 2 * r * 3;
    
    return result;
}
