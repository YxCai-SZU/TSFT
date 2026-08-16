#include <stddef.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == ((r) * (r));
    assigns \nothing;
*/
size_t func(size_t r) {
    // Variable declarations at top
    size_t res;
    
    //@ assert (1 <= (r) <= 100);
    
    //@ assert ((r) * (r)) <= 10000;
    
    res = r * r;
    
    //@ assert res == ((r) * (r));
    
    return res;
}
