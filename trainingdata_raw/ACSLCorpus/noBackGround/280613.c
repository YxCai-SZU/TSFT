#include <stdint.h>

/*@
    requires 1 <= n <= 1000000000;
    ensures ((\result) >= 2 * ((n) / 11));
    ensures ((\result) <= 2 * ((n) / 11) + 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    uint64_t res;

    if (n % 11 == 0)
    {
        res = n / 11 * 2;
        //@ assert ((res) >= 2 * ((n) / 11));
        //@ assert ((res) <= 2 * ((n) / 11) + 2);
        return res;
    }
    else if (n % 11 <= 5 && n >= 6)
    {
        res = n / 11 * 2 + 1;
        //@ assert ((res) >= 2 * ((n) / 11));
        //@ assert ((res) <= 2 * ((n) / 11) + 2);
        return res;
    }
    else
    {
        //@ assert n / 11 <= 1000000000;
        //@ assert n / 11 * 2 <= 2000000000;
        //@ assert n / 11 * 2 + 2 <= 2000000002;
        res = n / 11 * 2 + 2;
        //@ assert ((res) >= 2 * ((n) / 11));
        //@ assert ((res) <= 2 * ((n) / 11) + 2);
        return res;
    }
}
