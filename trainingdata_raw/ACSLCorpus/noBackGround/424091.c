#include <stdint.h>

/*@
    requires (0 <= (a) <= 0xFFFF) && (0 <= (b) <= 0xFFFF) && (0 <= (c) <= 0xFFFF);
    ensures \result == ((a) + (b) * (c));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    uint32_t ans;

    //@ assert (0 <= (b) <= 0xFFFF);
    //@ assert (0 <= (c) <= 0xFFFF);
    //@ assert 0 <= ((b) * (c)) <= 0xFFFF * 0xFFFF;
    ans = a + b * c;
    return ans;
}
