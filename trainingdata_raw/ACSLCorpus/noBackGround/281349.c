#include <stdint.h>

/*@
    requires (1 <= (n) <= 20 && 1 <= (m) <= 20);
    ensures \result <= n + m / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    uint32_t result;
    //@ assert (1 <= (n) <= 20 && 1 <= (m) <= 20);
    
    if (n * 2 > m) {
        result = m / 2;
    } else {
        result = n + (m - 2 * n) / 4;
    }
    
    //@ assert result == ((n) * 2 > (m) ? (m) / 2 : (n) + ((m) - 2 * (n)) / 4);
    //@ assert result <= n + m / 2;
    
    return result;
}
