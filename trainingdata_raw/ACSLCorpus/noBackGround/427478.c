#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint64_t n)
{
    int32_t ans;
    //@ assert 1 <= n <= 100;
    
    if (n % 2 == 0) {
        ans = 1;
    } else {
        ans = 0;
    }
    
    return ans;
}
