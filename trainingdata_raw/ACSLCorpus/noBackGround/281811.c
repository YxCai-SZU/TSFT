#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (6 * (r));
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi_approx;
    int64_t circumference;
    
    // Approximate value of PI * 2 (2 * PI) as 6
    pi_approx = 6;
    
    // Calculate circumference
    circumference = pi_approx * r;
    
    // Verification assertions
    //@ assert pi_approx == 6;
    //@ assert 6 * r >= 6;
    //@ assert circumference == pi_approx * r;
    //@ assert circumference == 6 * r;
    
    return circumference;
}
