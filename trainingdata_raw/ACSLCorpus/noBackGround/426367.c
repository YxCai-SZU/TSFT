#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100);
    ensures (((\result) == 0 && (x) < 101) || ((\result) == 1 && (x) >= 101));
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    uint32_t n;
    int32_t ans;
    
    n = 100;
    
    if (x < 101) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        ans = 1;
        //@ assert ans == 1;
    }
    
    return ans;
}
