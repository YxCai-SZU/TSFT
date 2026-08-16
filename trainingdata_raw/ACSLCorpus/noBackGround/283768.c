#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == n * n;
    assigns \nothing;
*/
size_t func(size_t n) {
    // Variable declarations at top of scope
    size_t res;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    //@ assert 1 <= n * n && n * n <= 10000;
    
    res = n * n;
    
    //@ assert res == n * n;
    
    return res;
}
