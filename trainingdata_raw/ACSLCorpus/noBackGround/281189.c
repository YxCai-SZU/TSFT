#include <stdint.h>

/*@
    requires (1 <= (x) <= 179);
    ensures \result <= 360;
    ensures \result == 360 - (x * 2) || \result == x * 2;
    assigns \nothing;
*/
uint32_t func(uint32_t x) {
    uint32_t ans = 0;
    
    //@ assert x * 2 <= 360;
    //@ assert 360 >= x * 2;
    
    if (x <= 180) {
        ans = 360 - (x * 2);
        //@ assert ans == 360 - (x * 2);
    } else {
        ans = x * 2;
        //@ assert ans == x * 2;
    }
    
    //@ assert ans == 360 - (x * 2) || ans == x * 2;
    return ans;
}
