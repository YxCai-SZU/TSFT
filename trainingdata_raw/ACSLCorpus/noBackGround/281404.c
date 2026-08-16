#include <stdint.h>

/*@
    requires ((a) <= 0x10000000 && (b) <= 0x10000000 && (c) <= 0x10000000);
    ensures \result == ((a) | (b) | (c));
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    // Variable declarations at top of scope
    uint32_t ans;

    //@ assert a <= 0x10000000;
    //@ assert b <= 0x10000000;
    //@ assert c <= 0x10000000;

    ans = a | b | c;
    return ans;
}
