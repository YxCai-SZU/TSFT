#include <stdint.h>

/*@
    requires (2 <= (n) <= 100) && (2 <= (m) <= 100);
    ensures \result == (n - 1) * (m - 1);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Declare all variables at the top
    uint64_t result;

    //@ assert 1 <= (n - 1) <= 99;
    //@ assert 1 <= (m - 1) <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    result = (n - 1) * (m - 1);
    return result;
}
