#include <stdint.h>

/*@
    requires n <= 65535;
    ensures \result == n * (n + 1) / 2;
    assigns \nothing;
*/
uint32_t is_triangular(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert n <= 65535;
    //@ assert n * (n + 1) / 2 <= 2147450880;

    result = n * (n + 1) / 2;
    
    //@ assert result == n * (n + 1) / 2;
    return result;
}
