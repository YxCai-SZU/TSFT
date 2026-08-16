#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000000 &&
        1 <= (k) <= 1000000000);
    ensures (k > ((n) / 2 + (n) % 2)) ==> \result == 0;
    ensures (k <= ((n) / 2 + (n) % 2)) ==> \result == n - k;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    // Variable declarations at top of scope
    uint64_t result;

    //@ assert ((n) / 2 + (n) % 2) <= 500000000 + 500000000;
    //@ assert n - k <= 1000000000;

    if (k > n / 2 + n % 2)
    {
        result = 0;
    }
    else
    {
        result = n - k;
    }

    return result;
}
