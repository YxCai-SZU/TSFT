#include <stdint.h>

/*@
    requires (1 <= (N) <= 1000000);
    ensures \result == (((N) - 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t N)
{
    //@ assert N - 1 >= 0;
    uint32_t ans;
    
    ans = (N - 1) / 2;
    
    //@ assert ans == (((N) - 1) / 2);
    return ans;
}
