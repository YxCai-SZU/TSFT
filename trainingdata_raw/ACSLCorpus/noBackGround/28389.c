#include <stdint.h>

/*@
    requires (0 <= (n) <= 65535);
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures \result <= 2147483647;
    assigns \nothing;
*/
uint32_t find_triangular(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert n * (n + 1) <= 4294967295;
    //@ assert n * (n + 1) / 2 <= 2147483647;
    
    result = n * (n + 1) / 2;
    
    //@ assert result == ((n) * ((n) + 1) / 2);
    //@ assert result <= 2147483647;
    
    return result;
}
