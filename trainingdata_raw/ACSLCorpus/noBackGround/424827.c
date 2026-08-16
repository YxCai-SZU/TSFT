#include <stdint.h>

/*@
    requires (0 <= (n) && (n) <= 65535);
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures \result <= 2147483647;
*/
uint32_t find_triangular_num(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t ret;
    
    //@ assert n <= 65535;
    //@ assert n + 1 <= 65536;
    //@ assert n * (n + 1) <= 4294967295;
    //@ assert n * (n + 1) / 2 <= 2147483647;
    
    ret = n * (n + 1) / 2;
    return ret;
}
