#include <stdint.h>

/*@
    requires (0 <= (a) <= 0x49);
    ensures \result == ((a) + ((a) * (a)) + ((a) * (a) * (a)));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    //@ assert (0 <= (a) <= 0x49);
    //@ assert a * a <= 0x49 * 0x49;
    //@ assert a * a * a <= 0x49 * 0x49 * 0x49;
    //@ assert a + (a * a) <= 0x49 + (0x49 * 0x49);
    //@ assert a + (a * a) + (a * a * a) <= 0x49 + (0x49 * 0x49) + (0x49 * 0x49 * 0x49);
    
    return a + (a * a) + (a * a * a);
}
