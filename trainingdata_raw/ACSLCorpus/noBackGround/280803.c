#include <stdbool.h>

/*@
    requires (-100 <= (a) <= 100 && -100 <= (b) <= 100 && -100 <= (c) <= 100);
    ensures (a == b && a != c) ==> \result == c;
    ensures (a == c && a != b) ==> \result == b;
    ensures (b == c && a != b) ==> \result == a;
    ensures (a != b && a != c && b != c) ==> \result == 0;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    if (a == b && a != c)
    {
        //@ assert a == b && a != c;
        result = c;
    }
    else if (a == c && a != b)
    {
        //@ assert a == c && a != b;
        result = b;
    }
    else if (b == c && a != b)
    {
        //@ assert b == c && a != b;
        result = a;
    }
    else
    {
        result = 0;
    }

    return result;
}
