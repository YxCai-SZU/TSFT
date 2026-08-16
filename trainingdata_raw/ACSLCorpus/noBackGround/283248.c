#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 20);
    ensures \result == ((n) + (n) * (n) + (n) * (n) * (n));
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    //@ assert (1 <= (n) && (n) <= 20);
    uint32_t result;
    result = n + n * n + n * n * n;
    //@ assert result == ((n) + (n) * (n) + (n) * (n) * (n));
    return result;
}
