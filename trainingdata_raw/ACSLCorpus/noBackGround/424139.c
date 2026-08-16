#include <stdint.h>

/*@
    requires 1 <= n <= 10000;
    ensures ((n) % 100 == 0) ==> \result == 0;
    ensures ((n) % 100 != 0) ==> \result == (100 - ((n) % 100));
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t n_unsigned;
    uint32_t mo;
    uint32_t res;

    n_unsigned = n;
    mo = n_unsigned % 100;

    if (mo == 0)
    {
        //@ assert ((n) % 100 == 0);
        res = 0;
    }
    else
    {
        //@ assert ((n) % 100 != 0);
        res = 100 - mo;
    }

    return res;
}
