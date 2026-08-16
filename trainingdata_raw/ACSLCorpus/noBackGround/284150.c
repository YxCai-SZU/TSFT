#include <stdint.h>

/*@
    requires (1 <= (a) <= 1000000000 &&
        1 <= (b) <= 1000000000 &&
        1 <= (c) <= 1000000000 &&
        1 <= (k) <= 1000000000);
    ensures \result >= -(int)k && \result <= (int)k;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    int32_t result;
    
    //@ assert (1 <= (a) <= 1000000000 &&         1 <= (b) <= 1000000000 &&         1 <= (c) <= 1000000000 &&         1 <= (k) <= 1000000000);
    
    if (a >= k)
    {
        result = (int32_t)k;
    }
    else if (a + b >= k)
    {
        result = (int32_t)a;
    }
    else
    {
        //@ assert a + b < k;
        //@ assert (int32_t)a - ((int32_t)k - (int32_t)(a + b)) >= -(int32_t)k;
        result = (int32_t)a - ((int32_t)k - (int32_t)(a + b));
    }
    
    return result;
}
