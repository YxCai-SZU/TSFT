#include <stdint.h>

/*@
    requires (0 <= (x) <= 100);
    ensures \result == ((x) * (x));
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t res;
    
    //@ assert (0 <= (x) <= 100);
    //@ assert ((x) * (x)) <= 10000;
    
    res = x * x;
    
    //@ assert res == ((x) * (x));
    return res;
}
