#include <stdint.h>
/*@
    requires (1 <= (a) && (a) <= 10000 &&
        1 <= (b) && (b) <= 10000 &&
        1 <= (c) && (c) <= 10000 &&
        1 <= (d) && (d) <= 10000);
    ensures \result == a + c || \result == a + d ||
            \result == b + c || \result == b + d;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t train;
    uint32_t bus;
    uint32_t res;

    //@ assert (1 <= (a) && (a) <= 10000 &&         1 <= (b) && (b) <= 10000 &&         1 <= (c) && (c) <= 10000 &&         1 <= (d) && (d) <= 10000);
    
    if (a < b) {
        train = a;
    } else {
        train = b;
    }
    //@ assert train == (((a) < (b)) ? (a) : (b));
    
    if (c < d) {
        bus = c;
    } else {
        bus = d;
    }
    //@ assert bus == (((c) < (d)) ? (c) : (d));
    
    //@ assert train == a || train == b;
    //@ assert bus == c || bus == d;
    
    res = train + bus;
    //@ assert res == train + bus;
    
    return res;
}
