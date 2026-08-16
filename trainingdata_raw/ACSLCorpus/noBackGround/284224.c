#include <stdint.h>

/*@
    requires 0 <= x <= 1000000000;
    ensures (x % 2 == 0 ==> \result == x / 2);
    ensures (x % 2 == 1 ==> \result == x / 2 + 1);
    assigns \nothing;
*/
uint64_t func(uint64_t x) {
    uint64_t half;
    uint64_t is_odd;
    uint64_t ans;
    
    half = x / 2;
    is_odd = x % 2;
    
    if (is_odd == 0) {
        ans = half;
        //@ assert ans == half;
    } else {
        ans = half + 1;
        //@ assert ans == half + 1;
    }
    
    return ans;
}
