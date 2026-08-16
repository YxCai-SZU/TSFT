#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * 3 * (r));
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi;
    int64_t circumference;
    
    pi = 3;
    
    //@ assert 2 * pi * r <= 2 * 3 * 100;
    //@ assert 2 * pi * r >= 2 * 3 * 1;
    
    circumference = 2 * pi * r;
    
    //@ assert circumference == 2 * 3 * r;
    
    return circumference;
}
