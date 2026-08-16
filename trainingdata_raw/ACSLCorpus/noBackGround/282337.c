#include <stdint.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result < 1000;
    ensures \result == ((1000 - (n) % 1000) % 1000);
*/
uint32_t func(uint32_t n)
{
    uint32_t res;
    
    //@ assert (1 <= (n) <= 10000);
    res = (1000 - n % 1000) % 1000;
    //@ assert res == ((1000 - (n) % 1000) % 1000);
    //@ assert res < 1000;
    
    return res;
}
