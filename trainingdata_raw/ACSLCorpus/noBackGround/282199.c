#include <stdint.h>

/*@
    requires (0 <= (n) <= 2896);
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures \result <= n * n;
    assigns \nothing;
*/
uint32_t triangular_number(uint32_t n)
{
    // Variable declarations at top
    uint32_t ret;

    //@ assert (0 <= (n) <= 2896);
    
    //@ assert n <= 2896;
    //@ assert ((n) * ((n) + 1) / 2) <= 2896 * (2896 + 1) / 2;
    
    //@ assert ((n) * ((n) + 1) / 2) <= n * n;
    
    ret = n * (n + 1) / 2;
    
    //@ assert ret == ((n) * ((n) + 1) / 2);
    //@ assert ret <= n * n;
    
    return ret;
}
