#include <limits.h>

/*@
    requires (-100 <= (a) <= 100 &&
        -100 <= (b) <= 100 &&
        -100 <= (c) <= 100 &&
        -100 <= (d) <= 100);
    ensures (((\result) == (a) || (\result) == (b) || (\result) == (c) || (\result) == (d)) &&
        (\result) >= (a) &&
        (\result) >= (b) &&
        (\result) >= (c));
*/
int func(int a, int b, int c, int d)
{
    int ans;

    if (a >= b)
    {
        if (a >= c)
        {
            if (a >= d)
            {
                ans = a;
            }
            else
            {
                ans = d;
            }
        }
        else
        {
            if (c >= d)
            {
                ans = c;
            }
            else
            {
                ans = d;
            }
        }
    }
    else
    {
        if (b >= c)
        {
            if (b >= d)
            {
                ans = b;
            }
            else
            {
                ans = d;
            }
        }
        else
        {
            if (c >= d)
            {
                ans = c;
            }
            else
            {
                ans = d;
            }
        }
    }

    //@ assert ans == a || ans == b || ans == c || ans == d;
    //@ assert ans >= a;
    //@ assert ans >= b;
    //@ assert ans >= c;

    return ans;
}
