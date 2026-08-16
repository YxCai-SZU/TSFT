#include <stddef.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result <= a && \result <= b && ((\result) > 0);
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    size_t d;
    size_t e;

    d = a;
    e = b;

    /*@
        loop invariant ((d) <= (a)) && ((e) <= (b));
        loop invariant ((d) > 0) && ((e) > 0);
        loop assigns d, e;
        loop variant d + e;
    */
    while (d != e)
    {
        if (d > e)
        {
            //@ assert d - e <= a;
            d = d - e;
        }
        else
        {
            //@ assert e - d <= b;
            e = e - d;
        }
    }

    //@ assert d <= a && d <= b && ((d) > 0);
    return d;
}
