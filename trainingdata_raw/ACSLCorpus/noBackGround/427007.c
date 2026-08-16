#include <stddef.h>

/*@
    requires (1 <= (n) && (n) <= 100000);
    ensures \result == (((n) - 1) / 2 + 1);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t ret;

    //@ assert (1 <= (n) && (n) <= 100000);
    ret = (n - 1) / 2 + 1;
    //@ assert ret == (((n) - 1) / 2 + 1);
    return ret;
}
