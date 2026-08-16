#include <stdint.h>

/*@
    requires (0 <= (i) && (i) <= 65535);
    ensures \result == (((i) * ((i) + 1)) / 2);
    ensures \result <= 2147483647;
    assigns \nothing;
*/
uint32_t count_triangular_num(uint32_t i)
{
    // Variable declarations at scope top
    uint32_t result;
    
    //@ assert i + 1 <= 65536;
    
    //@ assert i * (i + 1) <= 4294967295;
    
    result = i * (i + 1) / 2;
    
    //@ assert result == (((i) * ((i) + 1)) / 2);
    
    return result;
}
