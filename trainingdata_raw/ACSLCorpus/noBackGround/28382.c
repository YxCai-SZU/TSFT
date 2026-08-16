#include <stdbool.h>

/*@
    requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100) && (-100 <= (c) && (c) <= 100);
    ensures (a == b && b == c) ==> \result == 1;
    ensures (a != b && b != c && a != c) ==> \result == 3;
    ensures ((a == b || b == c || a == c) && !(a == b && b == c)) ==> \result == 2;
    assigns \nothing;
*/
int func(long long a, long long b, long long c)
{
    int result;

    //@ assert (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100) && (-100 <= (c) && (c) <= 100);

    if (a == b && b == c)
    {
        //@ assert a == b && b == c;
        result = 1;
    }
    else if (a == b || a == c || b == c)
    {
        //@ assert (a == b || b == c || a == c) && !(a == b && b == c);
        result = 2;
    }
    else
    {
        //@ assert a != b && b != c && a != c;
        result = 3;
    }

    return result;
}
