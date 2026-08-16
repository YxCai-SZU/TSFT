#include <stdint.h>

/*@
    requires a <= 0xFFFF;
    ensures \result == ((a) + ((a) * (a)) / 0x10000);
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert a <= 0xFFFF;

    //@ assert a * a <= 0xFFFF * 0xFFFF;

    //@ assert (a * a) / 0x10000 <= (0xFFFF * 0xFFFF) / 0x10000;

    //@ assert a + (a * a) / 0x10000 <= 0xFFFF + (0xFFFF * 0xFFFF) / 0x10000;

    result = a + (a * a) / 0x10000;
    return result;
}
