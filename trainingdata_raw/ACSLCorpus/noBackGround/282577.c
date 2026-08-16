#include <stdint.h>

/*@
    requires (2 <= (n) <= 100 && 2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert 2 <= n && n <= 100;
    //@ assert 2 <= m && m <= 100;
    //@ assert n - 1 >= 1;
    //@ assert m - 1 >= 1;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    result = (int32_t)((n - 1) * (m - 1));
    return result;
}
