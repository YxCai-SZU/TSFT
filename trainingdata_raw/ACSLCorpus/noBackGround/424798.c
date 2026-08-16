#include <stdbool.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == true <==> (a + b == c || b + c == a || c + a == b);
    assigns \nothing;
*/
bool func(long a, long b, long c)
{
    bool ok = false;

    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (1 <= (c) <= 100);
    //@ assert a + b <= 200;
    //@ assert b + c <= 200;
    //@ assert c + a <= 200;

    if (a + b == c)
    {
        ok = true;
    }
    if (b + c == a)
    {
        ok = true;
    }
    if (c + a == b)
    {
        ok = true;
    }

    //@ assert ok == true <==> (a + b == c || b + c == a || c + a == b);
    return ok;
}
