#include <stdint.h>

/*@
    requires (0 <= (n) <= 2896);
    ensures \result == ((n) * ((n) + 1) / 2);
    assigns \nothing;
*/
uint32_t find_triangular_num(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert n <= 2896;
    //@ assert n * (n + 1) / 2 <= 2896 * 2897 / 2;
    //@ assert n * (n + 1) <= 2896 * 2897;

    result = n * (n + 1) / 2;
    return result;
}
