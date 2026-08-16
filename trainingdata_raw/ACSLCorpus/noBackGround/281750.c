#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100);
    ensures \result == (2 * (a) - 1);
    assigns \nothing;
*/
uintptr_t func(uintptr_t a)
{
    // Variable declarations at scope top
    uintptr_t result;

    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (2 * (a) - 1) <= 200;

    result = 2 * a - 1;
    return result;
}
