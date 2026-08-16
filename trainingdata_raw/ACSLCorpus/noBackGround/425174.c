#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == (((n) + 1) / 2);
    ensures \result >= 1;
    ensures \result <= 50000;
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t res;
    //@ assert (1 <= (n) && (n) <= 100000);
    res = (n + 1) / 2;
    //@ assert res == (((n) + 1) / 2);
    //@ assert res >= 1;
    //@ assert res <= 50000;
    return res;
}
