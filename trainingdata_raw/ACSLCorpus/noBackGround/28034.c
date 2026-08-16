#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (6 * (r));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx;
    int64_t circumference;

    //@ assert (1 <= (r) <= 100);
    
    pi_approx = 3;
    circumference = 2 * pi_approx * r;
    
    //@ assert circumference == 6 * r;
    
    return circumference;
}
