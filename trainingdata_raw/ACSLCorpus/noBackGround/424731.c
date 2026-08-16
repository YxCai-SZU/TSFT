#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000);
    ensures \result == ((((x) - 1) / 2) * (((x) - 1) / 2));
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    // Variable declarations at top of scope
    uint64_t result;

    //@ assert x > 0 && x <= 1000000000;
    //@ assert (x - 1) <= 1000000000;
    //@ assert (x - 1) / 2 <= 500000000;
    //@ assert ((x - 1) / 2) * ((x - 1) / 2) <= 500000000 * 500000000;

    result = ((x - 1) / 2) * ((x - 1) / 2);
    return result;
}
