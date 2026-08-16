#include <stddef.h>

/*@
    requires (1 <= (a) <= 10);
    requires (1 <= (b) <= 10);
    requires (1 <= (c) <= 10);
    ensures \result == (((a) + (b) + 1) / 2 <= (c) ?
        (a) + (b) + 1 + (c) - ((a) + (b) + 1) / 2 :
        (b) + (c));
    assigns \nothing;
*/
size_t func(size_t a, size_t b, size_t c)
{
    // Variable declarations at scope top
    size_t ans;

    //@ assert a + b <= 20;
    //@ assert a + b + 1 <= 21;
    //@ assert (a + b + 1) / 2 <= 10;
    //@ assert c <= 10;
    //@ assert a + b + 1 + c - (a + b + 1) / 2 <= 31;

    if ((a + b + 1) / 2 <= c)
    {
        ans = a + b + 1 + c - (a + b + 1) / 2;
    }
    else
    {
        ans = b + c;
    }

    return ans;
}
