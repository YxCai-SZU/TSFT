#include <stdint.h>

/*@
    requires n <= 1000;
    ensures ((\result) == (n) * (n));
    ensures ((\result) >= 0);
*/
uint32_t find_square_num(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert n * n <= 1000 * 1000;
    
    result = n * n;
    
    //@ assert result == n * n;
    //@ assert result >= 0;
    
    return result;
}
