#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    // Variable declarations at top of scope
    int32_t x;
    int32_t y;
    int32_t result;

    //@ assert (1 <= (n) && (n) <= 100);
    
    // Arithmetic bounds verification
    //@ assert 800 * n <= 800 * 100;
    //@ assert (n / 15) * 200 <= 100 * 200;
    //@ assert 800 * n - (n / 15) * 200 >= 0;

    x = 800 * (int32_t)n;
    y = ((int32_t)(n / 15)) * 200;
    result = x - y;
    
    //@ assert result == ((n) * 800 - ((n) / 15) * 200);
    return result;
}
