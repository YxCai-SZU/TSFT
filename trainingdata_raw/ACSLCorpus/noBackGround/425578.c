#include <stdint.h>

/*@
    requires 0 <= x <= 1;
    ensures (x == 0 ==> \result == 1) && (x == 1 ==> \result == 0);
    assigns \nothing;
*/
int32_t func(uint32_t x)
{
    int32_t result;
    uint32_t a;

    a = 1 - x;

    if (a == 1)
    {
        //@ assert a == 1;
        result = 1;
    }
    else
    {
        //@ assert a == 0;
        result = 0;
    }

    return result;
}
