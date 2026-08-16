#include <stdint.h>

/*@
    requires 0 <= x <= 1;
    ensures \result == 1 - x;
    ensures ((\result) == 0 || (\result) == 1);
*/
uintptr_t func(uintptr_t x)
{
    uintptr_t y;
    
    //@ assert 0 <= x <= 1;
    
    y = 1 - x;
    
    //@ assert y == 1 - x;
    //@ assert ((y) == 0 || (y) == 1);
    
    return y;
}
