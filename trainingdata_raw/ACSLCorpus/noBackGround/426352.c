#include <stdint.h>

/*@
    requires (0 <= (x) <= 1);
    ensures \result == (1 - (x));
    ensures (0 <= (\result) <= 1);
*/
uint64_t func(uint64_t x)
{
    uint64_t res;
    
    //@ assert 0 <= 1 - x <= 1;
    
    res = 1 - x;
    
    //@ assert res == (1 - (x));
    //@ assert (0 <= (res) <= 1);
    
    return res;
}
