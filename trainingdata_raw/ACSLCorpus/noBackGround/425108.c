#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (6 * (n) * ((n) - 1) + 1);
    assigns \nothing;
*/
uint32_t find_star_num(uint32_t n)
{
    // Variable declarations at scope top
    uint32_t result;

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert 6 * n <= 600;
    //@ assert 6 * n * (n - 1) <= 600 * 100;

    result = 6 * n * (n - 1) + 1;
    //@ assert result == (6 * (n) * ((n) - 1) + 1);
    return result;
}
