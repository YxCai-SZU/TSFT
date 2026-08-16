#include <stdint.h>

/*@
    requires 0 <= x <= 100;
    requires 0 <= y <= 100;
    ensures \result <= 100;
    ensures \result >= 0;
    ensures \result == x || \result == y || \result == x * y;
    assigns \nothing;
*/
uint32_t test_complex_conditional_logic(uint32_t x, uint32_t y) {
    uint32_t ans;
    
    //@ assert (0 <= (x) <= 100);
    //@ assert (0 <= (y) <= 100);
    
    if (x > y) {
        ans = x;
    } else {
        ans = y;
    }
    
    //@ assert ans == x || ans == y;
    //@ assert (0 <= (ans) <= 100);
    
    return ans;
}
