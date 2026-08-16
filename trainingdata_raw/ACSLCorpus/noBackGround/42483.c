#include <stdint.h>

/*@
    requires (0 <= (n) <= 2926);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    //@ assert n <= 2926;
    //@ assert n * (n + 1) / 2 <= 2926 * (2926 + 1) / 2;
    //@ assert n * (n + 1) <= 4294967295;
    
    return n * (n + 1) / 2;
}
