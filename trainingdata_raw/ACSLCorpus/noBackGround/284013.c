#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (6 * (r));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi_approx;
    int64_t circumference;
    
    pi_approx = 3;
    
    //@ assert pi_approx == 3;
    //@ assert 1 <= r <= 100;
    //@ assert 2 * pi_approx * r == 6 * r;
    
    circumference = 2 * pi_approx * r;
    
    return circumference;
}
