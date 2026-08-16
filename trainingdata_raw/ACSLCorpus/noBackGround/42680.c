#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100) && (2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    //@ assert 1 <= n - 1 && n - 1 <= 99;
    //@ assert 1 <= m - 1 && m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    return (n - 1) * (m - 1);
}
