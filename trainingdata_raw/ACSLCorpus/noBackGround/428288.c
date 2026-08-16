#include <stdint.h>

/*@
    requires 1 <= a && a <= 10;
    ensures \result == a * (1 + a + a * a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    //@ assert a * a <= 100;
    uint32_t a_pow_2 = a * a;
    
    //@ assert a * a * a <= 1000;
    uint32_t a_pow_3 = a * a * a;
    
    //@ assert 1 + a + a_pow_2 <= 112;
    //@ assert a * (1 + a + a_pow_2) <= 1120;
    
    return a * (1 + a + a_pow_2);
}
