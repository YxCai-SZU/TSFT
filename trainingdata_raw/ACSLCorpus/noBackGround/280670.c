#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
    ensures \result == (100 * ((n) - (m)) + 1900 * (m));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t result;
    //@ assert (1 <= (n) <= 100 &&         1 <= (m) <= (n) &&         (m) <= 5);
    
    result = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    
    //@ assert result >= 0;
    //@ assert result == (100 * ((n) - (m)) + 1900 * (m));
    
    return result;
}
