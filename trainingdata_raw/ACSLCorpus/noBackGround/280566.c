#include <stdint.h>

/*@
    requires (1 <= (x) && (x) <= 100);
    ensures \result == x * x * x * 2;
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    //@ assert (1 <= (x) && (x) <= 100);
    //@ assert x * x <= 10000;
    //@ assert x * x * x <= 1000000;
    //@ assert x * x * x * 2 <= 2000000;
    
    return x * x * x * 2;
}
