#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures (a == b && a != c) ==> \result == c;
    ensures (a != b && b == c) ==> \result == a;
    ensures (a == c && a != b) ==> \result == b;
    ensures (a == b && a == c) ==> \result == a;
    ensures (a != b && b != c && a != c) ==> \result == a;
*/
int func(int a, int b, int c)
{
    int result;

    if (a == b)
    {
        if (b != c)
        {
            //@ assert ((a) == (b) && (a) != (c));
            result = c;
        }
        else
        {
            //@ assert ((a) == (b) && (a) == (c));
            result = a;
        }
    }
    else if (b == c)
    {
        //@ assert ((a) != (b) && (b) == (c));
        result = a;
    }
    else if (a == c)
    {
        //@ assert ((a) == (c) && (a) != (b));
        result = b;
    }
    else
    {
        //@ assert ((a) != (b) && (b) != (c) && (a) != (c));
        result = a;
    }

    return result;
}
