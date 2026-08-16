#include <limits.h>

/*@
    predicate in_range(integer v) = -100 <= v <= 100;

    logic integer sorted_result(integer a, integer b, integer c) =
        (a == b && b != c) ? c :
        (b == c && a != b) ? a :
        (c == a && b != c) ? b :
        a;
*/


int func(int a, int b, int c)
{
    int x;
    int y;
    int z;
    int temp;

    x = a;
    y = b;
    z = c;

    //@ assert in_range(x) && in_range(y) && in_range(z);

    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }

    //@ assert x <= y;

    if (y > z)
    {
        temp = y;
        y = z;
        z = temp;
    }

    //@ assert y <= z;

    if (x > y)
    {
        temp = x;
        x = y;
        y = temp;
    }

    //@ assert x <= y && y <= z;

    if (x == y && y == z)
    {
        //@ assert x == y && y == z;
        return x;
    }
    else if (x == y && y != z)
    {
        //@ assert x == y && y != z;
        return z;
    }
    else if (y == z && x != y)
    {
        //@ assert y == z && x != y;
        return x;
    }
    else
    {
        //@ assert x != y && y != z;
        return y;
    }
}
