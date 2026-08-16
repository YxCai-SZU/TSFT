#include <stdint.h>

/*@
    predicate valid_range(integer s) = 1 <= s <= 100;
    
    logic integer square(integer s) = s * s;
    
    lemma square_bounds:
        \forall integer s; valid_range(s) ==> 1 <= square(s) <= 10000;
*/

/*@
    requires valid_range(s);
    ensures \result == square(s);
    assigns \nothing;
*/
int32_t func(int32_t s)
{
    // Variable declarations at scope top
    int32_t result;
    
    //@ assert valid_range(s);
    
    //@ assert 1 <= s * s <= 10000;
    
    result = s * s;
    
    //@ assert result == square(s);
    
    return result;
}
