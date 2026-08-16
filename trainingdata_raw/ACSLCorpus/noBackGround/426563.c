#include <stdint.h>

/*@
    requires 2 <= n <= 100000;
    requires 1 <= k <= 100000;
    ensures \result == (n > k ? n - k : 0);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t k) {
    uint32_t res;
    
    if (n > k) {
        //@ assert ((n) > (k));
        //@ assert ((n) - (k) <= 100000);
        res = n - k;
    } else {
        res = 0;
    }
    
    return res;
}
