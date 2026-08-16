#include <stdbool.h>

/*@
    requires -100 <= a <= 100;
    requires -100 <= b <= 100;
    requires -100 <= c <= 100;
    ensures (a == b && a != c) ==> \result == c;
    ensures (a == c && a != b) ==> \result == b;
    ensures (b == c && a != b) ==> \result == a;
    ensures (a != b && a != c && b != c) ==> \result == 0;
    assigns \nothing;
*/
long func(long a, long b, long c)
{
    long result;

    if (a == b && a == c)
    {
        result = 0;
    }
    else if (a == b)
    {
        //@ assert a == b && a != c;
        result = c;
    }
    else if (a == c)
    {
        //@ assert a == c && a != b;
        result = b;
    }
    else if (b == c)
    {
        //@ assert b == c && a != b;
        result = a;
    }
    else
    {
        //@ assert a != b && a != c && b != c;
        result = 0;
    }

    return result;
}
