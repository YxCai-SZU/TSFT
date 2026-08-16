#include <limits.h>

/*@
    requires (1 <= (x) <= 1000000000000000);
    ensures \result >= (((x) / 11) * 2);
    ensures \result <= (((x) / 11) * 2 + 2);
    assigns \nothing;
*/
unsigned long long func(unsigned long long x)
{
    unsigned long long q;
    unsigned long long r;
    unsigned long long res;

    q = x / 11;
    r = x % 11;

    if (r == 0)
    {
        res = q * 2;
        //@ assert res == (((x) / 11) * 2);
        //@ assert res <= (((x) / 11) * 2 + 2);
        return res;
    }
    else if (r <= 10)
    {
        res = q * 2 + 1;
        //@ assert res >= (((x) / 11) * 2);
        //@ assert res <= (((x) / 11) * 2 + 2);
        return res;
    }
    else
    {
        res = q * 2 + 2;
        //@ assert res >= (((x) / 11) * 2);
        //@ assert res == (((x) / 11) * 2 + 2);
        return res;
    }
}
