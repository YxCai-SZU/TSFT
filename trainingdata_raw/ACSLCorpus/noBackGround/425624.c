#include <stdint.h>

/*@
    requires ((a) == 7);
    ensures ((\result) == (a));
    assigns \nothing;
*/
uint32_t func(uint32_t a)
{
    uint32_t res;

    //@ assert a == 7;
    res = a;
    //@ assert res == a;
    return res;
}
