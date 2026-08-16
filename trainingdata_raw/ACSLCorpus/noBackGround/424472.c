#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result <= n + m / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    uint32_t result = 0;
    uint32_t remaining_n = n;
    uint32_t remaining_m = m;

    if (n < m / 2 + 1)
    {
        result += n;
        remaining_m -= 2 * n;
        //@ assert 0 <= remaining_m <= 100 * 2;
        //@ assert remaining_m / 4 <= 100;
        result += remaining_m / 4;
        return result;
    }
    else
    {
        //@ assert m / 2 + 1 <= n + m / 2;
        return m / 2 + 1;
    }
}
