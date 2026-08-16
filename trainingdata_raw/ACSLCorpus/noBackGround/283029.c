#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000000);
    ensures \result == ((((n) - 1) * (n)) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at top of scope
    uint64_t result;

    //@ assert n > 0 && n <= 1000000000;
    //@ assert n - 1 >= 0;
    //@ assert (n - 1) * n <= 1000000000 * 999999999;

    result = ((n - 1) * n) / 2;
    return result;
}
