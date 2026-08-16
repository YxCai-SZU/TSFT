#include <stdint.h>

/*@
    requires (1 <= (x) <= 100000);
    ensures \result == 0 || \result == 1;
    ensures ((\result) == 1 ==> ((((x)) / 100) % 5 == 0 || (((x)) / 100) % 5 == 1));
    ensures ((\result) == 0 ==> ((((x)) / 100) % 5 != 0 && (((x)) / 100) % 5 != 1));
*/
uint32_t func(uint32_t x)
{
    uint32_t c;
    uint32_t res;

    c = x / 100;

    if (c % 5 == 0 || c % 5 == 1)
    {
        res = 1;
    }
    else
    {
        res = 0;
    }

    //@ assert res == 1 ==> (x / 100) % 5 == 0 || (x / 100) % 5 == 1;
    //@ assert res == 0 ==> (x / 100) % 5 != 0 && (x / 100) % 5 != 1;

    return res;
}
