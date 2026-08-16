#include <stdint.h>

/*@
    requires ((a) <= 8 && (b) <= 8 && (c) <= 8);
    ensures \result == ((a) * (b) * (c));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t res;
    uint32_t tmp;

    //@ assert a <= 8 && b <= 8 && c <= 8;
    
    tmp = a * b;
    //@ assert tmp <= 64;
    
    res = tmp * c;
    //@ assert res <= 512;
    
    return res;
}
