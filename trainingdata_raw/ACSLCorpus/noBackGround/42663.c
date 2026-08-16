#include <stdint.h>

/*@
    requires (2 <= (a) <= 100) && (2 <= (b) <= 100);
    ensures ((\result) == ((a) - 1) * ((b) - 1));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t ans;
    
    //@ assert 1 <= a - 1 <= 99;
    //@ assert 1 <= b - 1 <= 99;
    //@ assert (a - 1) * (b - 1) <= 99 * 99;
    
    ans = (a - 1) * (b - 1);
    
    //@ assert ((ans) == ((a) - 1) * ((b) - 1));
    return ans;
}
