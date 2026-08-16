#include <stdint.h>

/*@
    requires (2 <= (k) && (k) <= (n) && (n) <= 1000000000);
    ensures \result <= (((n) - 1 + ((k) - 1 - 1)) / ((k) - 1));
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t k)
{
    uint64_t ans;
    //@ assert (2 <= (k) && (k) <= (n) && (n) <= 1000000000);
    ans = (n - 1 + (k - 1 - 1)) / (k - 1);
    //@ assert ans <= (((n) - 1 + ((k) - 1 - 1)) / ((k) - 1));
    return ans;
}
