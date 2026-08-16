#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
int32_t func(int32_t r)
{
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert (1 <= (r) <= 100);
    //@ assert 1 <= r <= 100;
    
    //@ assert 1 <= r * r <= 10000;
    //@ assert r * r == r * r;
    
    result = r * r;
    
    //@ assert result == ((r) * (r));
    
    return result;
}
