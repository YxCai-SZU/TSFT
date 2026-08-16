#include <stdint.h>

/*@
    requires (0 <= (a) <= 50) && (0 <= (b) <= 50) && (0 <= (c) <= 50);
    ensures \result >= 0 && \result <= 2;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans;
    
    //@ assert a + b + 1 <= 101;
    //@ assert a + b + 1 + b <= 152;
    
    if (c <= a + b + 1)
    {
        ans = 0;
    }
    else if (a + b + 1 + b <= c)
    {
        ans = 2;
    }
    else
    {
        ans = 1;
    }
    
    return ans;
}
