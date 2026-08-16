#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    logic integer square(integer r) = r * r;
    lemma square_bounds: \forall integer r; valid_range(r) ==> 1 <= square(r) && square(r) <= 10000;
*/

/*@
    requires valid_range(r);
    ensures \result == square(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert valid_range(r);
    //@ assert square(r) <= 10000;
    //@ assert square(r) >= 1;
    
    result = r * r;
    
    //@ assert result == square(r);
    return result;
}
