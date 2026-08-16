#include <stdint.h>

/*@
    requires (0 <= (n) && (n) <= 65535);
    ensures \result == (((n) * ((n) + 1)) / 2);
    assigns \nothing;
*/
uint32_t find_triangular(uint32_t n) {
    // Variable declarations at top of scope
    uint32_t ret;
    
    //@ assert (0 <= (n) && (n) <= 65535);
    
    ret = (n * (n + 1)) / 2;
    
    //@ assert ret == (((n) * ((n) + 1)) / 2);
    return ret;
}
