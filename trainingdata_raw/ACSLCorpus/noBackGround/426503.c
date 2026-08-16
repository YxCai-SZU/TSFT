#include <limits.h>

/*@
    requires (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    requires ((a) <= (b)) && ((c) <= (d));
    ensures \result == ((b) * (d)) || 
            \result == ((a) * (c)) || 
            \result == ((a) * (d)) || 
            \result == ((b) * (c));
*/
long func(long a, long b, long c, long d)
{
    long max_ab;
    long ac;
    long bd;
    long ad;
    long bc;

    //@ assert (-10000 <= (a) <= 10000) && (-10000 <= (b) <= 10000) && (-10000 <= (c) <= 10000) && (-10000 <= (d) <= 10000);
    //@ assert ((a) <= (b)) && ((c) <= (d));

    ac = a * c;
    bd = b * d;
    ad = a * d;
    bc = b * c;

    //@ assert -100000000 <= ac <= 100000000;
    //@ assert -100000000 <= bd <= 100000000;
    //@ assert -100000000 <= ad <= 100000000;
    //@ assert -100000000 <= bc <= 100000000;

    if (ac > bd)
    {
        if (ac > ad)
        {
            if (ac > bc)
            {
                max_ab = ac;
            }
            else
            {
                max_ab = bc;
            }
        }
        else
        {
            if (ad > bc)
            {
                max_ab = ad;
            }
            else
            {
                max_ab = bc;
            }
        }
    }
    else
    {
        if (bd > ad)
        {
            if (bd > bc)
            {
                max_ab = bd;
            }
            else
            {
                max_ab = bc;
            }
        }
        else
        {
            if (ad > bc)
            {
                max_ab = ad;
            }
            else
            {
                max_ab = bc;
            }
        }
    }

    //@ assert max_ab == bd || max_ab == ac || max_ab == ad || max_ab == bc;
    return max_ab;
}
