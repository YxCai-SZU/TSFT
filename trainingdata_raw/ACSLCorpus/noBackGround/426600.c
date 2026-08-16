#include <stddef.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result == (((a) * 3 + (p)) / 2);
    assigns \nothing;
*/
size_t func(size_t a, size_t p)
{
    size_t a_tripled;
    size_t sum;
    size_t pies;

    a_tripled = a * 3;
    sum = a_tripled + p;
    pies = sum / 2;

    //@ assert pies == (((a) * 3 + (p)) / 2);
    return pies;
}
