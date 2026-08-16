#include <limits.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures ((a) == (b) && (a) != (c)) ==> \result == c;
    ensures ((a) == (c) && (a) != (b)) ==> \result == b;
    ensures ((b) == (c) && (a) != (b)) ==> \result == a;
*/
int func(int a, int b, int c)
{
    int result;

    if (a == b)
    {
        //@ assert a == b;
        result = c;
    }
    else if (a == c)
    {
        //@ assert a == c;
        result = b;
    }
    else if (b == c)
    {
        //@ assert b == c;
        result = a;
    }
    else
    {
        result = 0;
    }

    return result;
}
