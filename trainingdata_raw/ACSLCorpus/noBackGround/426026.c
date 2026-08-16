#include <stdint.h>

/*@
    requires n <= 2950;
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures ((n) >= 0 && (\result) == (n) * ((n) + 1) / 2);
    ensures \result <= n * (n + 1);
*/
uint32_t find_triangular_number(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert n <= 2950;
    //@ assert n * (n + 1) <= 2950 * (2950 + 1);
    //@ assert n * (n + 1) <= 8707250;
    
    result = n * (n + 1) / 2;
    
    //@ assert result == ((n) * ((n) + 1) / 2);
    //@ assert ((n) >= 0 && (result) == (n) * ((n) + 1) / 2);
    //@ assert result <= n * (n + 1);
    
    return result;
}
