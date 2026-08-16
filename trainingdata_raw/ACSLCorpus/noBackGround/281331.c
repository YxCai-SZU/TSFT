#include <stdint.h>

/*@
    requires (0 <= (n) <= 2958);
    ensures \result == ((n) * ((n) + 1) / 2);
    ensures \result >= 0;
*/
uint32_t find_triangular_num(uint32_t n)
{
    // Variable declarations at top of scope
    uint32_t result;

    //@ assert n + 1 <= 2959;
    //@ assert n * (n + 1) <= 2958 * 2959;
    //@ assert n * (n + 1) >= 0;

    result = n * (n + 1) / 2;
    return result;
}
