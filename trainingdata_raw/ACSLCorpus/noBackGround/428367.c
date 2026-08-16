#include <stdint.h>

/*@
    requires 1 <= n && n <= 100;
    ensures \result == 800 * n - (n / 15) * 200;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    int32_t x;
    
    //@ assert 1 <= n && n <= 100;
    
    //@ assert 800 * n <= 800 * 100;
    
    //@ assert n / 15 <= n;
    
    //@ assert (n / 15) * 200 <= n * 200;
    
    x = 800 * (int32_t)n - (int32_t)(n / 15) * 200;
    
    return x;
}
