#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures ((\result) % 2 == 0);
    ensures n <= \result <= 2 * n;
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;

    if (n % 2 == 0) {
        result = n;
    } else {
        //@ assert n * 2 <= 2 * n;
        result = n * 2;
    }

    return result;
}
