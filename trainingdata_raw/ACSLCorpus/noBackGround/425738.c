#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    requires 1 <= c && c <= 100;
    ensures \result >= 1 && \result <= 3;
    ensures ((a) == (b) && (b) == (c)) ==> \result == 1;
    ensures (((a) == (b) || (b) == (c) || (c) == (a)) && !((a) == (b) && (b) == (c))) ==> \result == 2;
    ensures ((a) != (b) && (b) != (c) && (c) != (a)) ==> \result == 3;
*/
int func(int a, int b, int c)
{
    int result;

    if (a == b && b == c)
    {
        result = 1;
    }
    else if (a == b || b == c || c == a)
    {
        result = 2;
    }
    else
    {
        result = 3;
    }

    //@ assert result >= 1 && result <= 3;

    if (a == b && b == c)
    {
        //@ assert result == 1;
    }
    else if (a == b || b == c || c == a)
    {
        //@ assert result == 2;
    }
    else
    {
        //@ assert result == 3;
    }

    return result;
}
