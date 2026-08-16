#include <stdint.h>

/*@
    requires 1 <= a <= 100;
    ensures \result == a + a * a + a * a * a;
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    //@ assert a * a <= 100 * 100;
    //@ assert a * a * a <= 100 * 100 * 100;
    //@ assert a + a * a + a * a * a <= 100 + 100 * 100 + 100 * 100 * 100;
    
    return a + a * a + a * a * a;
}
