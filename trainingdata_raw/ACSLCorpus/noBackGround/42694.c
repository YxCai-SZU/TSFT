#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 1000000);
    ensures \result == (((n) - 1) / 2);
    assigns \nothing;
*/
size_t func(size_t n)
{
    // Variable declarations at top of scope
    size_t res;

    //@ assert n > 0 && n <= 1000000;
    res = (n - 1) / 2;
    //@ assert res == (((n) - 1) / 2);
    return res;
}
