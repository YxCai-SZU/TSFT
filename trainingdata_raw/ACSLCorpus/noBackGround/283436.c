#include <stdint.h>

/*@
    requires 1 <= a <= 10;
    ensures \result == a * (1 + a + a * a);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert 1 <= a && a <= 10;
    
    //@ assert a + a <= 20;
    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;
    //@ assert 1 + a + a * a <= 111;
    //@ assert a * (1 + a + a * a) <= 1110;

    result = a * (1 + a + a * a);
    
    //@ assert result == a * (1 + a + a * a);
    return result;
}
