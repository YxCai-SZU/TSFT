#include <stdint.h>

/*@
    requires (0 <= (n) <= 2965);
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures \result <= 4294967295;
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    //@ assert n <= 2965;
    
    //@ assert n * (n + 1) <= 2965 * 2966;
    
    return n * (n + 1) / 2;
}
