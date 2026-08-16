#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (3 * (r) * (r));
    ensures \result >= 0;
    assigns \nothing;
*/
int32_t func(int32_t r) {
    int32_t ans;
    
    //@ assert (1 <= (r) <= 100);
    
    //@ assert (3 * (r) * (r)) <= 3 * 100 * 100;
    
    ans = 3 * r * r;
    
    //@ assert ans == (3 * (r) * (r));
    //@ assert ans >= 0;
    
    return ans;
}
