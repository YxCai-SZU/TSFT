#include <stddef.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
size_t func(size_t r)
{
    size_t ans;
    
    //@ assert r * r <= 10000;
    
    ans = r * r;
    
    return ans;
}
