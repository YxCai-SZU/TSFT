#include <stdint.h>

/*@
    requires \true;
    ensures ((\result) >= (a0) && (\result) >= (a1) && (\result) >= (a2) &&
        ((\result) == (a0) || (\result) == (a1) || (\result) == (a2)));
    assigns \nothing;
*/
uint32_t max_tuple(uint32_t a0, uint32_t a1, uint32_t a2)
{
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t ret;

    x = a0;
    y = a1;
    z = a2;

    if (x >= y && x >= z)
    {
        //@ assert x >= y;
        //@ assert x >= z;
        ret = x;
    }
    else if (y >= x && y >= z)
    {
        //@ assert y >= x;
        //@ assert y >= z;
        ret = y;
    }
    else
    {
        //@ assert z >= x;
        //@ assert z >= y;
        ret = z;
    }

    //@ assert ((ret) >= (a0) && (ret) >= (a1) && (ret) >= (a2) &&         ((ret) == (a0) || (ret) == (a1) || (ret) == (a2)));
    return ret;
}
