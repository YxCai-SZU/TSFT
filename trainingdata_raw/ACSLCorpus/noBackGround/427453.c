#include <stdint.h>

/*@ requires (1 <= (n) && (n) <= 20 &&
      1 <= (m) && (m) <= 20);
    ensures \result == (((m) * 2 + 1 > (n)) ? (n) : (m) * 2);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert 2 <= m * 2 <= 40;
    
    if (m * 2 + 1 > n) {
        result = n;
    } else {
        result = m * 2;
    }
    
    //@ assert result == (((m) * 2 + 1 > (n)) ? (n) : (m) * 2);
    return result;
}
