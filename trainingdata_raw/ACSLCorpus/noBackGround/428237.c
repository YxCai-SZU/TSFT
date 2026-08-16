#include <stdint.h>

/*@
    requires (0 <= (n) <= 65535);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    //@ assert n + 1 <= 65536;
    //@ assert n * (n + 1) <= 4294967295;
    return n * (n + 1) / 2;
}
