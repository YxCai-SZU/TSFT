#include <stddef.h>

/*@
    requires (1 <= (a) <= 10000 &&
        1 <= (b) <= 10000 &&
        1 <= (c) <= 10000 &&
        1 <= (d) <= 10000);
    ensures \result <= b + d;
    ensures \result >= ((a) < (b) ? (a) : (b));
*/
size_t func(size_t a, size_t b, size_t c, size_t d)
{
    size_t s;
    size_t t;

    //@ assert (1 <= (a) <= 10000 &&         1 <= (b) <= 10000 &&         1 <= (c) <= 10000 &&         1 <= (d) <= 10000);

    if (a < b)
    {
        s = a;
    }
    else
    {
        s = b;
    }

    //@ assert s == ((a) < (b) ? (a) : (b));
    //@ assert s <= b;

    t = b + d - s;

    if (t < c)
    {
        //@ assert t < c;
        //@ assert s + t <= b + d;
        return s + t;
    }

    if (d < c)
    {
        //@ assert d < c;
        //@ assert s + d <= b + d;
        return s + d;
    }

    //@ assert s + c <= b + d;
    return s + c;
}
