#include <stddef.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
size_t func(size_t n) {
    // Variable declarations at scope top
    size_t res;
    
    //@ assert (1 <= (n) <= 100);
    
    //@ assert ((n) * ((n) + 1) / 2) <= 100 * (100 + 1) / 2;
    
    res = n * (n + 1) / 2;
    
    //@ assert res == ((n) * ((n) + 1) / 2);
    
    return res;
}
