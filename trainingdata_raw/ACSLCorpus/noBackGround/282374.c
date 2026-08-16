#include <stddef.h>

/*@
    requires (1 <= (a) <= 20 && 1 <= (b) <= 20 && 1 <= (t) <= 20);
    ensures \result == ((b) * ((t) / (a)));
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t t)
{
    // Variable declarations at scope top
    size_t ans;
    
    //@ assert a >= 1;
    //@ assert b >= 1;
    //@ assert t >= 1;
    //@ assert a <= 20;
    //@ assert b <= 20;
    //@ assert t <= 20;
    
    //@ assert t / a <= 20;
    //@ assert b * (t / a) <= 400;
    
    ans = b * (t / a);
    return ans;
}
