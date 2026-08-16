#include <stdint.h>

/*@
    requires (2 <= (k) <= (n) <= 1000000000);
    ensures \result == (((n) - 2) / ((k) - 1) + 1);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert n - 2 >= 0;
    //@ assert k - 1 >= 1;
    //@ assert (n - 2) / (k - 1) <= 1000000000;

    result = (n - 2) / (k - 1) + 1;
    return result;
}
