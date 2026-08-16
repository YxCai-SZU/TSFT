#include <limits.h>

/*@
    requires (1 <= (a) <= 10000);
    requires (1 <= (b) <= 10000);
    requires (1 <= (c) <= 10000);
    requires (1 <= (d) <= 10000);
    ensures \result == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long min1;
    long min2;
    long result;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    if (a < b)
    {
        min1 = a;
    }
    else
    {
        min1 = b;
    }

    //@ assert min1 == ((a) < (b) ? (a) : (b));

    if (c < d)
    {
        min2 = c;
    }
    else
    {
        min2 = d;
    }

    //@ assert min2 == ((c) < (d) ? (c) : (d));

    result = min1 + min2;

    //@ assert result == ((a) < (b) ? (a) : (b)) + ((c) < (d) ? (c) : (d));
    return result;
}
