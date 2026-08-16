#include <stdint.h>

/*@
    requires ((a) < 0x100 && (b) < 0x100);
    ensures \result == ((a) + (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    //@ assert a < 0x100 && b < 0x100;
    //@ assert a + b < 0x200;
    return a + b;
}
