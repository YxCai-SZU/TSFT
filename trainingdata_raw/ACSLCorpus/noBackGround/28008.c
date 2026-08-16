#include <stddef.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result == (((a) * 3 + (p)) / 2);
    assigns \nothing;
*/
size_t func(size_t a, size_t p)
{
    size_t result;

    //@ assert a * 3 <= 300;
    //@ assert a * 3 + p <= 400;
    result = (a * 3 + p) / 2;
    return result;
}
