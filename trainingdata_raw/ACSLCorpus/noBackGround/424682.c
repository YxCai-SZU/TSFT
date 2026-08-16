#include <stddef.h>

/*@
    requires 0 <= a <= 50;
    requires 0 <= b <= 50;
    requires 0 <= c <= 50;
    ensures \result >= 0;
    ensures \result <= 2;
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c)
{
    size_t result;

    if (a == b && b == c)
    {
        //@ assert ((a) == (b) && (b) == (c));
        //@ assert a == c;
        result = 1;
    }
    else if (a == b || b == c || c == a)
    {
        //@ assert (((a) == (b) || (b) == (c) || (a) == (c)) && !((a) == (b) && (b) == (c)));
        //@ assert a == b || b == c || a == c;
        //@ assert !(a == b && b == c);
        result = 2;
    }
    else
    {
        //@ assert ((a) != (b) && (b) != (c) && (a) != (c));
        //@ assert a != b && b != c && a != c;
        result = 0;
    }

    //@ assert result >= 0;
    //@ assert result <= 2;
    return result;
}
