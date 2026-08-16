#include <stdint.h>

/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    requires (1 <= (c) <= 100);
    ensures \result <= b + c;
    ensures \result >= b;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t res;
    //@ assert c <= 100;
    //@ assert b + c <= 200;
    
    if (a < c) {
        res = b + a;
    } else {
        res = b + c;
    }
    
    return res;
}
