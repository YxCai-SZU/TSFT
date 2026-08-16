#include <stdint.h>

/*@
    predicate valid_radius(integer r) = 1 <= r <= 100;
    logic integer circumference_formula(integer r) = 6 * r;
*/

/*@
    requires valid_radius(r);
    ensures \result == circumference_formula(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi_approx;
    int64_t circumference;
    
    pi_approx = 3;
    
    //@ assert 0 <= pi_approx * r <= 300;
    
    circumference = 2 * pi_approx * r;
    
    //@ assert circumference == 6 * r;
    
    return circumference;
}
