#include <limits.h>

/*@
    requires (-1000000000 <= (a) <= 1000000000) && (-1000000000 <= (b) <= 1000000000) && (-1000000000 <= (c) <= 1000000000) && (-1000000000 <= (d) <= 1000000000);
    requires a <= b && c <= d;
    ensures \result == b * d || \result == a * d || \result == b * c || \result == a * c;
    assigns \nothing;
*/
long func(long a, long b, long c, long d)
{
    long max_val;
    long ans;

    //@ assert (-1000000000000000000 <= (a) * (c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (a) * (d) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b) * (c) <= 1000000000000000000);
    //@ assert (-1000000000000000000 <= (b) * (d) <= 1000000000000000000);

    if (a * c > a * d)
    {
        if (a * c > b * d)
        {
            if (a * c > b * c)
            {
                max_val = a * c;
            }
            else
            {
                max_val = b * c;
            }
        }
        else
        {
            max_val = b * d;
        }
    }
    else
    {
        if (a * d > b * d)
        {
            if (a * d > b * c)
            {
                max_val = a * d;
            }
            else
            {
                max_val = b * c;
            }
        }
        else
        {
            max_val = b * d;
        }
    }

    ans = a * c;
    ans = (ans > a * d) ? ans : a * d;
    ans = (ans > b * d) ? ans : b * d;
    ans = (ans > b * c) ? ans : b * c;

    //@ assert ans == b * d || ans == a * d || ans == b * c || ans == a * c;

    return ans;
}
