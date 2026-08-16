#include <stddef.h>

/*@
    requires (0 <= (a) && (a) <= 100 && 0 <= (p) && (p) <= 100);
    ensures \result == (((a) * 3 + (p)) / 2);
    assigns \nothing;
*/
size_t func(size_t a, size_t p)
{
    size_t k;
    size_t res;

    k = a * 3 + p;
    //@ assert k == a * 3 + p;
    res = k / 2;
    //@ assert res == (a * 3 + p) / 2;
    return res;
}
