#include <stdint.h>

/*@
    requires (0 <= (a) <= 100 &&
        2 <= (b) <= 1000 &&
        (b) % 2 == 0);
    ensures ((\result) >= 0 &&
        (\result) <= (b) &&
        ((\result) == (b) || (\result) == (b) / 2 || (\result) == 0));
*/
uint32_t func(uint32_t a, uint32_t b) {
    uint32_t ans;
    
    //@ assert (0 <= (a) <= 100 &&         2 <= (b) <= 1000 &&         (b) % 2 == 0);
    
    if (a < 13) {
        ans = 0;
        //@ assert ans == 0;
    } else if (a >= 13 && a < 20) {
        ans = b / 2;
        //@ assert ans == b / 2;
    } else {
        ans = b;
        //@ assert ans == b;
    }
    
    //@ assert ans == b || ans == b / 2 || ans == 0;
    //@ assert ((ans) >= 0 &&         (ans) <= (b) &&         ((ans) == (b) || (ans) == (b) / 2 || (ans) == 0));
    
    return ans;
}
