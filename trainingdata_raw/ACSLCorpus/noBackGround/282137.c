#include <stdint.h>

/*@
    requires (0 <= (n) <= 2954);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t find_triangular(uint32_t n) {
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert (0 <= (n) <= 2954);
    
    result = n * (n + 1) / 2;
    
    //@ assert result == ((n) * ((n) + 1) / 2);
    return result;
}
