#include <stdint.h>

/*@
    requires (1 <= (n) <= 100000);
    ensures ((\result) == 1 || (\result) == 0 &&
        ((\result) == 1 ==> (n) % 100 <= 5 * ((n) / 100)) &&
        ((\result) == 0 ==> (n) % 100 > 5 * ((n) / 100)));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    uint32_t x;
    uint32_t y;
    int32_t res;

    //@ assert (1 <= (n) <= 100000);
    x = n / 100;
    y = n - 100 * x;

    //@ assert n / 100 <= 1000;
    //@ assert 5 * (n / 100) <= 5000;

    if (y <= 5 * x)
    {
        res = 1;
    }
    else
    {
        res = 0;
    }

    //@ assert ((res) == 1 || (res) == 0 &&         ((res) == 1 ==> (n) % 100 <= 5 * ((n) / 100)) &&         ((res) == 0 ==> (n) % 100 > 5 * ((n) / 100)));
    return res;
}
