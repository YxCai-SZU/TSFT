#include <stdint.h>

/*@
    predicate valid_radius(integer r) = 1 <= r <= 100;
    logic integer circumference(integer r) = 2 * 3 * r;
*/

/*@
    requires valid_radius(r);
    ensures \result == circumference(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t circumference;
    
    //@ assert 1 <= r <= 100;
    
    //@ assert 2 * 3 * r <= 2 * 3 * 100;
    
    circumference = 2 * 3 * r;
    
    //@ assert circumference == 2 * 3 * r;
    
    return circumference;
}
