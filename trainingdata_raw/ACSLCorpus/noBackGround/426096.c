#include <stdint.h>

/*@
    requires ((x) > 0 && (x) <= 10);
    requires ((y) > 0 && (y) <= 10);
    ensures \result == ((x) * (y));
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    //@ assert ((x) > 0 && (x) <= 10);
    //@ assert ((y) > 0 && (y) <= 10);
    //@ assert ((x) * (y)) <= 100;
    
    uint32_t res;
    res = x * y;
    
    //@ assert res == ((x) * (y));
    return res;
}
