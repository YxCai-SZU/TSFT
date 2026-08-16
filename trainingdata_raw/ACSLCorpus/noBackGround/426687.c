#include <stdint.h>

/*@
    requires (0 <= (n) && (n) < 1000);
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures 0 <= \result <= 4294967295;
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    //@ assert n + 1 <= 1001;
    //@ assert n * (n + 1) <= 1000 * 1001;
    //@ assert n * (n + 1) / 2 <= 500 * 1001;
    
    return n * (n + 1) / 2;
}
