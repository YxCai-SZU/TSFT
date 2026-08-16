#include <stdint.h>

/*@
    requires (1 <= (n) <= 100000 && 0 <= (k) <= (n) - 1);
    ensures \result == ((n) - (k) - 1);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    // Variable declarations at scope top
    uint64_t result;

    //@ assert (1 <= (n) <= 100000 && 0 <= (k) <= (n) - 1);
    //@ assert ((n) - (k) - 1) == n - k - 1;
    //@ assert ((n) - (k) - 1) <= n - 1;
    //@ assert ((n) - (k) - 1) >= 0;

    result = n - k - 1;
    //@ assert result == ((n) - (k) - 1);
    return result;
}
