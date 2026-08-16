#include <stdint.h>

/*@
    requires (2 <= (k) && (k) <= (n) && (n) <= 100000);
    ensures \result == ((n) - (k) + 1);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t k) {
    // Variable declarations at top of scope
    int32_t result;
    
    //@ assert k > 0;
    //@ assert n > 0;
    //@ assert n - k + 1 <= n;
    //@ assert n - k + 1 >= 0;
    //@ assert n - k + 1 <= 100000;
    
    result = (int32_t)(n - k + 1);
    return result;
}
