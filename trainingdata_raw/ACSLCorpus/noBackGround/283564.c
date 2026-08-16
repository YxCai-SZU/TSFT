#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures \result == ((((n) - 1) * (n)) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert n > 0;
    //@ assert n <= 1000000000;
    //@ assert n - 1 <= 1000000000;
    //@ assert (n - 1) * n <= 9223372036854775807 / 2;

    result = ((n - 1) * n) / 2;
    return result;
}
