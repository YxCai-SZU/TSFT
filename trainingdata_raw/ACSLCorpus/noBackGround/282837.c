#include <stdint.h>

/*@
    requires 0 <= n <= 65535;
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures \result <= 2147483647;
    assigns \nothing;
*/
uint32_t is_triangular(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t product;
    uint32_t result;

    //@ assert (0 <= (n) <= 65535);
    
    //@ assert n + 1 <= 65536;
    
    product = n * (n + 1);
    //@ assert product <= 4294967295;
    
    result = product / 2;
    //@ assert result == ((n) * ((n) + 1) / 2);
    
    return result;
}
