#include <stdint.h>

/*@
    requires (1 <= (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at top
    uint32_t a_pow2;
    uint32_t a_pow3;
    uint32_t result;

    //@ assert 1 <= a && a <= 10;
    
    //@ assert a + a * a + a * a * a <= 10 + 10 * 10 + 10 * 10 * 10;
    
    a_pow2 = a * a;
    //@ assert a_pow2 <= 100;
    
    a_pow3 = a_pow2 * a;
    //@ assert a_pow3 <= 1000;
    
    //@ assert a + a_pow2 + a_pow3 <= 1110;
    
    result = a + a_pow2 + a_pow3;
    return result;
}
