#include <stdint.h>

/*@
    requires 0 <= x <= 5 && 0 <= y <= 10 && 0 <= z <= 2;
    ensures \result == x * y * z;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y, uint32_t z)
{
    // Variable declarations at top of scope
    uint32_t res;

    //@ assert 0 <= x <= 5;
    //@ assert 0 <= y <= 10;
    //@ assert 0 <= z <= 2;
    
    //@ assert x * y <= 50;
    //@ assert x * y * z <= 100;
    
    res = x * y * z;
    return res;
}
