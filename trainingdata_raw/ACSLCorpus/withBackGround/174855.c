#include <stdint.h>

/*@
    predicate bounds(uint32_t x) = 0 <= x && x < 0x10000;
*/

/*@
    requires bounds(a) && bounds(b) && bounds(c);
    ensures \result == (a | b | c);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at top of scope
    uint32_t res;

    //@ assert bounds(a);
    //@ assert bounds(b);
    //@ assert bounds(c);
    
    res = a | b | c;
    return res;
}
