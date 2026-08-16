#include <stddef.h>

/*@
    requires (0 <= (a) <= 100) && (0 <= (p) <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
size_t func(size_t a, size_t p)
{
    size_t k;
    size_t pies;

    //@ assert (0 <= (a) <= 100) && (0 <= (p) <= 100);
    k = a * 3 + p;
    //@ assert ((a) * 3 + (p)) == k;
    //@ assert k >= 0;
    pies = k / 2;
    //@ assert pies >= 0;
    return pies;
}
