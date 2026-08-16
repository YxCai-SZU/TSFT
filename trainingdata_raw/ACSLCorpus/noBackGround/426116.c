#include <limits.h>

/*@
    requires (1 <= (n) <= 100) && (1 <= (m) <= 100);
    ensures (n < 10 && m < 10 ==> \result == 1) &&
            (n < 10 && m >= 10 ==> \result == -1) &&
            (n >= 10 && m < 10 ==> \result == 1) &&
            (n >= 10 && m >= 10 ==> \result == 0);
    assigns \nothing;
*/
int func(unsigned int n, unsigned int m)
{
    int res;

    //@ assert (1 <= (n) <= 100) && (1 <= (m) <= 100);

    if (n < 10 && m < 10)
    {
        //@ assert n < 10 && m < 10;
        res = 1;
        return res;
    }

    if (n < 10 && m >= 10)
    {
        //@ assert n < 10 && m >= 10;
        res = -1;
        return res;
    }

    if (n >= 10 && m < 10)
    {
        //@ assert n >= 10 && m < 10;
        res = 1;
        return res;
    }

    if (n >= 10 && m >= 10)
    {
        //@ assert n >= 10 && m >= 10;
        res = 0;
        return res;
    }

    //@ assert n < 10 && m < 10 || n < 10 && m >= 10 || n >= 10 && m < 10 || n >= 10 && m >= 10;
    res = 0;
    return res;
}
