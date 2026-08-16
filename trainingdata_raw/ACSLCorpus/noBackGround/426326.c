#include <limits.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> !(a != b && b != c && a != c);
    ensures \result == 3 ==> (a != b && b != c && a != c);
*/
int func(int a, int b, int c)
{
    int res = -1;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);

    if (a == b && b == c)
    {
        res = 1;
    }
    else if (a != b && b != c && a != c)
    {
        res = 3;
    }
    else
    {
        res = 2;
    }

    //@ assert res == 1 ==> (a == b && b == c);
    //@ assert res == 2 ==> !(a != b && b != c && a != c);
    //@ assert res == 3 ==> (a != b && b != c && a != c);

    return res;
}
