#include <stddef.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    // Variable declarations at scope top
    size_t ans;

    //@ assert n > 1 && m > 1;
    //@ assert n - 1 <= 99 && m - 1 <= 99;
    //@ assert 1 <= n - 1 && n - 1 <= 99;
    //@ assert 1 <= m - 1 && m - 1 <= 99;
    //@ assert (n - 1) * (m - 1) <= 99 * 99;

    ans = (n - 1) * (m - 1);
    
    //@ assert ans == (((n) - 1) * ((m) - 1));
    return ans;
}
