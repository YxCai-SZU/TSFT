#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000 &&
        1 <= (m) && (m) <= 1000000000);
    ensures \result >= 0;
    ensures \result <= ((n) + (m) / 4);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t rem;
    uint64_t div;
    uint64_t result;

    if (n >= m / 2)
    {
        //@ assert m / 2 <= ((n) + (m) / 4);
        result = m / 2;
    }
    else
    {
        rem = m - 2 * n;
        //@ assert rem <= m;
        div = rem / 4;
        //@ assert div <= m / 4;
        result = n + div;
    }

    return result;
}
