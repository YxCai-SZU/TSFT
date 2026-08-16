#include <limits.h>

/*@
    requires (1 <= (l) && (l) <= (r) && (r) <= 100 &&
        1 <= (d) && (d) <= 100);
    ensures \result >= 0;
    ensures \result <= r - l + 1;
    assigns \nothing;
*/
long func(long l, long r, long d)
{
    long count = 0;
    long i = l;

    /*@
        loop invariant ((1 <= ((l)) && ((l)) <= ((r)) && ((r)) <= 100 &&
        1 <= ((d)) && ((d)) <= 100) &&
        (l) <= (i) &&
        (i) <= (r) + 1 &&
        (count) >= 0 &&
        (count) <= (i) - (l) &&
        (i) - (l) <= (r) - (l) + 1);
        loop assigns i, count;
        loop variant r - i + 1;
    */
    while (i <= r)
    {
        long remainder = i;

        /*@
            loop invariant ((l) <= (i) && (i) <= (r) &&
        1 <= (d) && (d) <= 100 &&
        0 <= (remainder) &&
        (remainder) <= (i));
            loop assigns remainder;
            loop variant remainder;
        */
        while (remainder >= d)
        {
            //@ assert remainder >= d;
            remainder -= d;
        }

        /*@
            loop invariant ((l) <= (i) && (i) <= (r) &&
        1 <= (d) && (d) <= 100 &&
        (remainder) < (d));
            loop assigns remainder;
            loop variant d - remainder;
        */
        while (remainder < 0)
        {
            //@ assert remainder < 0;
            remainder += d;
        }

        if (remainder == 0)
        {
            //@ assert remainder == 0;
            count += 1;
        }

        i += 1;
    }

    //@ assert count >= 0;
    //@ assert count <= r - l + 1;
    return count;
}
