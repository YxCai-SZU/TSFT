#include <stdint.h>

/*@
    requires 0 <= a <= 1000000000;
    requires 0 <= b <= 1000000000;
    requires 0 <= c <= 1000000000;
    ensures \result >= 0;
    ensures \result <= a + b + 1;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c) {
    uint32_t ans;
    
    if (c <= a + b) {
        if (a < c) {
            ans = a + b + 1;
        } else {
            ans = c + 1;
        }
    } else {
        ans = b + 1;
    }
    
    //@ assert ((ans) >= 0);
    //@ assert ((ans) <= (a) + (b) + 1);
    
    return ans;
}
