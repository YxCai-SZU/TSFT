#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (c) <= 100 &&
        1 <= (k) <= (a) + (b) + (c) &&
        (a) + (b) >= (k));
    ensures \result <= (int)k;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    uint32_t n;
    
    //@ assert (1 <= (a) <= 100 &&         1 <= (b) <= 100 &&         1 <= (c) <= 100 &&         1 <= (k) <= (a) + (b) + (c) &&         (a) + (b) >= (k));
    
    if (k > a + b)
    {
        n = a + b;
    }
    else
    {
        n = k;
    }
    
    //@ assert n == ((k) > (a) + (b) ? (a) + (b) : (k));
    //@ assert n <= k;
    
    return (int32_t)n;
}
