#include <limits.h>

/*@
    requires (-1000 <= (a) <= 1000) && (-1000 <= (b) <= 1000);
    requires -1000000 <= a * b <= 1000000;
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b && \result >= a - b && \result >= a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    int x;
    int y;
    int z;
    int ans;

    x = a + b;
    y = a - b;
    z = a * b;

    //@ assert x == a + b;
    //@ assert y == a - b;
    //@ assert z == a * b;

    if (x > y && x > z)
    {
        ans = x;
    }
    else if (y > z)
    {
        ans = y;
    }
    else
    {
        ans = z;
    }

    //@ assert ans == (((x) >= (y) && (x) >= (z)) ? (x) : (((y) >= (z)) ? (y) : (z)));
    return ans;
}
