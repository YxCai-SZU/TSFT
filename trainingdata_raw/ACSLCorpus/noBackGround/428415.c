#include <stdint.h>

/*@
    requires (0 <= (n) <= 100 &&
        0 <= (m) <= 100 &&
        (n) <= (m) * 2);
    ensures \result == ((m) - (n) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert n <= 100;
    //@ assert m <= 100;
    //@ assert n <= m * 2;
    //@ assert m - n / 2 <= 100;

    result = m - n / 2;
    return result;
}
