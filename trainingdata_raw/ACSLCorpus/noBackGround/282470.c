#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    requires a + c <= UINT32_MAX && a + d <= UINT32_MAX && 
              b + c <= UINT32_MAX && b + d <= UINT32_MAX;
    ensures \result == a + c || \result == a + d || 
            \result == b + c || \result == b + d;
    ensures \result >= a + c && \result >= a + d && 
            \result >= b + c && \result >= b + d;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t max1;
    uint32_t max2;
    uint32_t res;

    //@ assert (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    
    if (a > b) {
        max1 = a;
    } else {
        max1 = b;
    }
    
    if (c > d) {
        max2 = c;
    } else {
        max2 = d;
    }
    
    //@ assert max1 == (a > b ? a : b);
    //@ assert max2 == (c > d ? c : d);
    
    res = max1 + max2;
    
    //@ assert res == ((max1) + (max2));
    //@ assert res >= a + c;
    
    return res;
}
