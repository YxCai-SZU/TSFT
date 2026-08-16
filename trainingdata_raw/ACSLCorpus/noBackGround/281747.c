#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> ((a) == (b) + (c) || (b) == (a) + (c) || (c) == (a) + (b));
    assigns \nothing;
 */
bool func(int a, int b, int c)
{
    int x;
    int y;
    int z;

    if (a > b)
    {
        if (a > c)
        {
            x = a;
            y = b;
            z = c;
        }
        else
        {
            x = c;
            y = b;
            z = a;
        }
    }
    else
    {
        if (b > c)
        {
            x = b;
            y = a;
            z = c;
        }
        else
        {
            x = c;
            y = a;
            z = b;
        }
    }

    if (x == y + z)
    {
        return true;
    }
    else
    {
        //@ assert x >= 1 && x <= 100;
        //@ assert y >= 1 && y <= 100;
        //@ assert z >= 1 && z <= 100;
        //@ assert y + z <= 200;
        return false;
    }
}
