#include <stdint.h>

/*@
    requires n < 0x00010000;
    ensures \result == n * n;
    ensures (0 <= (\result) < 0x10000 * 0x10000);
*/
uint32_t square_number(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;
    
    //@ assert n * n < 0x00010000 * 0x00010000;
    
    result = n * n;
    
    //@ assert ((result) == (n) * (n));
    //@ assert (0 <= (result) < 0x10000 * 0x10000);
    
    return result;
}
