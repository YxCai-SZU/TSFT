#include <stdint.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == (((c) * (d) < (a) * (b)) ? ((c) * (d)) : ((a) * (b)));
    ensures \result <= a * b;
    ensures \result <= c * d;
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d)
{
    // Variable declarations at scope top
    uint64_t product1;
    uint64_t product2;
    uint64_t result;
    
    //@ assert a * b <= 10000 * 10000;
    //@ assert c * d <= 10000 * 10000;
    
    product1 = a * b;
    product2 = c * d;
    
    if (product1 < product2) {
        result = product1;
    } else {
        result = product2;
    }
    
    return result;
}
