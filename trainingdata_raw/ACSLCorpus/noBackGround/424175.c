#include <stddef.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (p) && (p) <= 100);
    ensures \result == (((a) * 3 + (p)) / 2);
    assigns \nothing;
*/
size_t func(size_t a, size_t p)
{
    //@ assert (0 <= (a) && (a) <= 100 &&         0 <= (p) && (p) <= 100);
    //@ assert a * 3 + p <= 100 * 3 + 100;
    return (a * 3 + p) / 2;
}
