#include <stdint.h>

/*@
    requires ((a) < 0x80000000 && (b) < 0x80000000);
    ensures \result == a + b;
    ensures \result < 0x100000000;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    uint32_t res;
    //@ assert ((a) < 0x80000000 && (b) < 0x80000000);
    res = a + b;
    //@ assert res == a + b;
    //@ assert res < 0x100000000;
    return res;
}
