#include <stdint.h>

/*@
    requires (1 <= (k) && (k) <= (n) && (n) <= 100000000000000000);
    ensures \result <= n;
    ensures \result == ((n) - ((n) / (k)));
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    // Variable declarations at top of scope
    uint64_t result;

    //@ assert k > 0;
    //@ assert k <= n;
    //@ assert n / k <= n;
    //@ assert n - (n / k) <= n;

    result = n - (n / k);
    return result;
}
