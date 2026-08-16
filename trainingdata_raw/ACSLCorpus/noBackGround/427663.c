#include <stdint.h>

/*@
    requires (0 <= (n) <= 65535);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    //@ assert (0 <= (n) <= 65535);
    //@ assert ((n) * ((n) + 1) / 2) <= 2147450880;
    
    uint32_t result;
    result = n * (n + 1) / 2;
    
    //@ assert result == ((n) * ((n) + 1) / 2);
    return result;
}
