#include <stdint.h>

/*@
    requires (0 <= (x) <= 1);
    ensures \result == ((x) == 0 ? 1 : 0);
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    int32_t ans;
    
    //@ assert (0 <= (x) <= 1);
    
    if (x == 0) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    //@ assert 0 <= ans <= 1;
    //@ assert ans == ((x) == 0 ? 1 : 0);
    
    return ans;
}
