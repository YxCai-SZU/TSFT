#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (k) <= 100);
    ensures ((\result) <= (n));
    assigns \nothing;
*/
uint32_t min_tasty_cookies(uint32_t n, uint32_t k) {
    uint32_t result;
    
    if (n > k) {
        //@ assert n - k <= n;
        result = n - k;
    } else {
        //@ assert 0 <= n;
        result = 0;
    }
    
    return result;
}
