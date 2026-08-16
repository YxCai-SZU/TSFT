#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && a <= b;
    requires (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000) && c <= d;
    ensures \result == a * d || \result == b * c || \result == a * c || \result == b * d;
*/
long func(long a, long b, long c, long d)
{
    long max_val;
    long max_val2;
    long ans;

    //@ assert (-1000000000 <= (a) <= 1000000000);
    //@ assert (-1000000000 <= (c) <= 1000000000);
    //@ assert (-1000000000 <= (d) <= 1000000000);
    //@ assert (-1000000000000000000 <= (a) * (c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (a) * (d) <= 1000000000000000000);

    if (a * c > a * d)
    {
        max_val = a * c;
    }
    else
    {
        max_val = a * d;
    }

    //@ assert (-1000000000 <= (b) <= 1000000000);
    //@ assert (-1000000000000000000 <= (b) * (c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b) * (d) <= 1000000000000000000);

    if (b * c > b * d)
    {
        max_val2 = b * c;
    }
    else
    {
        max_val2 = b * d;
    }

    if (max_val > max_val2)
    {
        ans = max_val;
    }
    else
    {
        ans = max_val2;
    }

    return ans;
}
