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
    int32_t r;
    
    x = 800;
    y = 200;
    
    //@ assert (1 <= (n) && (n) <= 100);
    r = (int32_t)n * x - (int32_t)(n / 15) * y;
    
    //@ assert r == ((n) * 800 - ((n) / 15) * 200);
    return r;
}
