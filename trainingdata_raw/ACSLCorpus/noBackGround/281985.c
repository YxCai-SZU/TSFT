#include <stdint.h>

/*@ requires (1 <= (n) && 1 <= (m) && (n) <= 100000 && (m) <= 100000);
    ensures \result >= 0;
    ensures \result <= ((n) + (m) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    uint32_t count;
    
    count = 0;
    //@ assert count == 0;
    
    if (n > m / 2) {
        count += m / 2;
    } else {
        count += n;
    }
    //@ assert count >= 0;
    
    if (m > 2 * n) {
        count += (m - 2 * n) / 4;
    }
    //@ assert count >= 0;
    
    //@ assert count <= ((n) + (m) / 2);
    
    return count;
}
