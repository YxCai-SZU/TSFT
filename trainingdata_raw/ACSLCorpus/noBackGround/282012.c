#include <stdint.h>
/*@
    requires (0 <= (n) <= 2896);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    //@ assert (0 <= (n) <= 2896);
    uint32_t ret;
    //@ assert n * (n + 1) <= 2896 * (2896 + 1);
    //@ assert n * (n + 1) / 2 >= 0;
    //@ assert n * (n + 1) / 2 <= 2896 * (2896 + 1) / 2;
    ret = n * (n + 1) / 2;
    //@ assert ret == ((n) * ((n) + 1) / 2);
    return ret;
}
