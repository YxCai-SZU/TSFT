#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (a) * (a) + (a) * (a) * (a));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t a1;
    uint32_t a2;
    uint32_t a3;
    uint32_t result;

    //@ assert 1 <= a && a <= 10;
    
    a1 = a;
    a2 = a * a;
    a3 = a * a * a;
    
    //@ assert a3 == a * a * a;
    
    result = a1 + a2 + a3;
    
    //@ assert result == a + a * a + a * a * a;
    
    return result;
}
