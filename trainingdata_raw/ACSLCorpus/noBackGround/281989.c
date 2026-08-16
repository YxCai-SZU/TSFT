#include <stdint.h>

/*@
    requires (0 <= (n) <= 2895);
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures \result <= 2896 * 2897 / 2;
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t ret;

    //@ assert n <= 2895;
    //@ assert n + 1 <= 2896;
    //@ assert n * (n + 1) <= 2895 * 2896;

    ret = n * (n + 1) / 2;
    return ret;
}
