#include <stddef.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result <= a;
    ensures \result <= b;
    ensures \result <= c;
    ensures \result == a || \result == b || \result == c;
    ensures ((\result) <= (a) && (\result) <= (b) && (\result) <= (c) &&
        ((\result) == (a) || (\result) == (b) || (\result) == (c)));
*/
size_t func(size_t a, size_t b, size_t c)
{
    size_t result;

    if (a < b)
    {
        if (a < c)
        {
            //@ assert a <= a;
            result = a;
        }
        else
        {
            //@ assert c <= a;
            result = c;
        }
    }
    else
    {
        if (b < c)
        {
            //@ assert b <= a;
            result = b;
        }
        else
        {
            //@ assert c <= a;
            result = c;
        }
    }

    //@ assert ((result) <= (a) && (result) <= (b) && (result) <= (c) &&         ((result) == (a) || (result) == (b) || (result) == (c)));
    return result;
}
