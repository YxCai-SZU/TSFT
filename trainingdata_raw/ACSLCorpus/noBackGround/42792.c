#include <stdint.h>

/*@
    requires 0 <= x <= 1000000000;
    ensures ((x) % 5 == 0) ==> \result == 0;
    ensures ((x) % 5 != 0) ==> \result == (5 - ((x) % 5));
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t five;
    uint64_t ret;

    five = 5;
    //@ assert five == 5;

    if (x % five == 0)
    {
        //@ assert ((x) % 5 == 0);
        ret = 0;
    }
    else
    {
        //@ assert ((x) % 5 != 0);
        ret = five - (x % five);
    }

    return ret;
}
