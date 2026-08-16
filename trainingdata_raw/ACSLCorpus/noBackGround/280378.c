#include <stdint.h>

/*@
    requires (3 <= (n) && (n) <= 100);
    ensures \result == (((n) - 2) * 180);
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t ans;
    
    //@ assert n - 2 >= 1;
    //@ assert (((n) - 2) * 180) <= 100 * 180;
    
    ans = (int32_t)((n - 2) * 180);
    return ans;
}
