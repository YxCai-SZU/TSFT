#include <limits.h>

/*@
    requires x != y;
    requires (1 <= (x) <= 3);
    requires (1 <= (y) <= 3);
    ensures (1 <= (\result) <= 3);
    ensures \result != x;
    ensures \result != y;
*/
int func(int x, int y)
{
    int res;

    //@ assert x != y;
    //@ assert (1 <= (x) <= 3);
    //@ assert (1 <= (y) <= 3);

    if ((x == 1 && y == 2) || (x == 2 && y == 1))
    {
        res = 3;
    }
    else if ((x == 1 && y == 3) || (x == 3 && y == 1))
    {
        res = 2;
    }
    else
    {
        res = 1;
    }

    //@ assert (1 <= (res) <= 3);
    //@ assert res != x;
    //@ assert res != y;

    return res;
}
