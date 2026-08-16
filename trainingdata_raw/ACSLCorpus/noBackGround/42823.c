#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == ((a) * (b)) || \result == ((c) * (d));
    ensures 1 <= \result <= 10000 * 10000;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    // Variable declarations at scope top
    uint64_t x;
    uint64_t y;
    uint64_t result;
    
    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    //@ assert ((a) * (b)) <= 10000 * 10000;
    
    //@ assert (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    //@ assert ((c) * (d)) <= 10000 * 10000;
    
    x = a * b;
    y = c * d;
    
    //@ assert x >= 1;
    //@ assert y >= 1;
    
    if (x > y) {
        result = x;
    } else {
        result = y;
    }
    
    //@ assert result == x || result == y;
    return result;
}
