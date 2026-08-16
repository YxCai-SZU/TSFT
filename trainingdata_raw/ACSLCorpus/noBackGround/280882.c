#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result <= a * b;
    ensures \result == (((a) * (b) + 1) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    // Variable declarations at top of scope
    uint32_t c;
    uint32_t half_c;
    uint32_t result;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert a * b <= 10000;
    
    c = a * b;
    half_c = c / 2;
    
    if (c % 2 != 0) {
        result = half_c + 1;
    } else {
        result = half_c;
    }
    
    return result;
}
