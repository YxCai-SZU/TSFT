#include <stdint.h>

/*@
    requires 1 <= n && n <= 100000;
    ensures \result == ((n) % 1000 == 0 ? 0 : ((n) / 1000 + 1) * 1000 - (n));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    uint32_t num;
    uint32_t rem;
    uint32_t v;
    int32_t change;

    num = n / 1000;
    rem = n % 1000;

    if (rem == 0)
    {
        //@ assert n % 1000 == 0;
        change = 0;
        //@ assert change == 0;
    }
    else
    {
        //@ assert n % 1000 != 0;
        v = (num + 1) * 1000;
        //@ assert v == (n / 1000 + 1) * 1000;
        change = (int32_t)v - (int32_t)n;
        //@ assert change == (n / 1000 + 1) * 1000 - n;
    }

    //@ assert change == ((n) % 1000 == 0 ? 0 : ((n) / 1000 + 1) * 1000 - (n));
    return change;
}
