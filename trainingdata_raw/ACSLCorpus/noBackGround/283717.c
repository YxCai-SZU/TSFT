#include <stddef.h>

/*@
    requires (1 <= (n) <= 10000 && 1 <= (x) <= 10000);
    ensures \result <= n / x;
    ensures \result >= 0;
    assigns \nothing;
*/
size_t func(size_t n, size_t x) {
    // Variable declarations at top of scope
    size_t result;
    
    //@ assert (1 <= (n) <= 10000 && 1 <= (x) <= 10000);
    //@ assert n / x <= n / x;
    //@ assert n / x >= 0;
    //@ assert n / x <= n;
    
    result = n / x;
    
    //@ assert result <= n / x;
    //@ assert result >= 0;
    
    return result;
}
