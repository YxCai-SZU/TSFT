#include <limits.h>

/*@
    requires (-1000 <= (a) && (a) <= 1000) && (-1000 <= (b) && (b) <= 1000);
    requires -1000000 <= a * b && a * b <= 1000000;
    ensures \result == a + b || \result == a - b || \result == a * b;
    ensures \result >= a + b;
    ensures \result >= a - b;
    ensures \result >= a * b;
    assigns \nothing;
*/
int f(int a, int b)
{
    int x;
    int y;
    int z;
    int max1;
    int result;

    x = a + b;
    y = a - b;
    z = a * b;

    //@ assert x == a + b;
    //@ assert y == a - b;
    //@ assert z == a * b;

    if (x > y)
    {
        max1 = x;
    }
    else
    {
        max1 = y;
    }

    //@ assert max1 >= x && max1 >= y;

    if (max1 > z)
    {
        result = max1;
    }
    else
    {
        result = z;
    }

    //@ assert result >= max1 && result >= z;
    //@ assert result >= a + b;
    //@ assert result >= a - b;
    //@ assert result >= a * b;
    //@ assert result == a + b || result == a - b || result == a * b;

    return result;
}
