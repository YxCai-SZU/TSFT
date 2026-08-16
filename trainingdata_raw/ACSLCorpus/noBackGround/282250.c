#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * ((r) * (r)));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi_approx;
    int64_t area;
    
    pi_approx = 3;
    
    //@ assert 2 * r * pi_approx <= 600;
    //@ assert r * r <= 10000;
    //@ assert 3 * (r * r) <= 30000;
    
    area = 3 * (r * r);
    
    return area;
}
