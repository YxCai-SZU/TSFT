#include <stddef.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result <= a && \result <= b;
    ensures \result == a || \result == b;
    assigns \nothing;
*/
size_t func(size_t a, size_t b)
{
    size_t res;

    if (a < b)
    {
        //@ assert a <= a;
        //@ assert a <= b;
        res = a;
    }
    else
    {
        //@ assert b <= a;
        //@ assert b <= b;
        res = b;
    }

    return res;
}
