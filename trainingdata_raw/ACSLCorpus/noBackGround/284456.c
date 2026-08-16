#include <stddef.h>

/*@
    requires 2 <= n && n <= 100;
    requires 2 <= m && m <= 100;
    ensures \result == (n - 1) * (m - 1);
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    size_t ans;
    //@ assert n > 1 && n <= 100;
    //@ assert m > 1 && m <= 100;
    //@ assert n - 1 >= 1;
    //@ assert m - 1 >= 1;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;
    ans = (n - 1) * (m - 1);
    return ans;
}
