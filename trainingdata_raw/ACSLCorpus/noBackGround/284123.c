#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t y;
    int32_t ans;
    
    x = 800;
    y = 200;
    
    //@ assert x == 800 && y == 200;
    ans = x * (int32_t)n - y * (int32_t)(n / 15);
    
    //@ assert ans == 800 * (int32_t)n - 200 * (int32_t)(n / 15);
    return ans;
}
