#include <stdint.h>

/*@
    requires (2 <= (k) <= (n) <= 100000);
    ensures \result <= n - 1;
    ensures \result == (((n) - 1 + ((k) - 1 - 1)) / ((k) - 1));
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t k)
{
    uint32_t result;
    //@ assert (2 <= (k) <= (n) <= 100000);
    result = (n - 1 + (k - 1 - 1)) / (k - 1);
    //@ assert result == (((n) - 1 + ((k) - 1 - 1)) / ((k) - 1));
    //@ assert result <= n - 1;
    return result;
}
