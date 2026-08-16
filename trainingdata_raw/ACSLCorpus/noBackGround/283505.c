#include <stdint.h>

/*@
    requires (0 <= (n) && (n) <= 65535);
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t find_triangular(uint32_t n)
{
    // Declare all variables at the top
    uint32_t ret = 0;
    
    if (n == 0) {
        ret = 0;
    } else {
        //@ assert n > 0 && n <= 65535;
        //@ assert ((n) * ((n) + 1) / 2) <= 2147483647;
        //@ assert ((n) * ((n) + 1) / 2) >= 0;
        ret = n * (n + 1) / 2;
    }
    
    return ret;
}
