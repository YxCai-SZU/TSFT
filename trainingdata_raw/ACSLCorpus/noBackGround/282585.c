#include <limits.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures \result == (((a) == (b) && (b) == (c)) ? 1 :
        ((a) != (b) && (b) != (c) && (a) != (c)) ? 3 : 2);
    ensures (\result == 1 && a == b && b == c) ||
            (\result == 2 && a == b && a != c) ||
            (\result == 2 && a != b && b == c) ||
            (\result == 2 && a == c && b != c) ||
            (\result == 3 && a != b && b != c && a != c);
*/
int func(int a, int b, int c)
{
    int res;

    if (a == b && b == c)
    {
        res = 1;
        //@ assert a == b && b == c;
    }
    else if (a != b && b != c && a != c)
    {
        res = 3;
        //@ assert a != b && b != c && a != c;
    }
    else
    {
        res = 2;
        //@ assert (a == b && a != c) || (a != b && b == c) || (a == c && b != c);
    }

    return res;
}
