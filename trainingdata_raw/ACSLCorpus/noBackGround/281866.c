#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == ((a - b * 3) == (b * 3 - a));
*/
bool func(int a, int b)
{
    int x;
    int y;
    int tmp1;
    int tmp2;

    tmp1 = a - b * 3;
    tmp2 = b * 3 - a;

    //@ assert tmp1 == ((a) - (b) * 3);
    //@ assert tmp2 == ((b) * 3 - (a));

    if (tmp1 < tmp2)
    {
        x = tmp1;
    }
    else
    {
        x = tmp2;
    }

    //@ assert x == ((((a)) - ((b)) * 3) < (((b)) * 3 - ((a))) ? (((a)) - ((b)) * 3) : (((b)) * 3 - ((a))));

    if (tmp1 > tmp2)
    {
        y = tmp1;
    }
    else
    {
        y = tmp2;
    }

    //@ assert y == ((((a)) - ((b)) * 3) > (((b)) * 3 - ((a))) ? (((a)) - ((b)) * 3) : (((b)) * 3 - ((a))));

    //@ assert (x == y) == (((a) - (b) * 3) == ((b) * 3 - (a)));

    return x == y;
}
