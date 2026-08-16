#include <stdint.h>

/*@
    requires (0 <= (a) <= 0xffff && 0 <= (b) <= 0xffff);
    ensures \result == ((a) + 2 * (b));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t res;

    //@ assert (0 <= (a) <= 0xffff && 0 <= (b) <= 0xffff);
    //@ assert 0 <= ((a) + 2 * (b)) <= 0xffff + 2 * 0xffff;

    res = a + 2 * b;

    //@ assert res == ((a) + 2 * (b));
    return res;
}
