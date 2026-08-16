#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (3 * (n) * (n));
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    // Variable declarations at top of scope
    int64_t ans;

    //@ assert 1 <= n && n <= 100;
    //@ assert 3 * n <= 300;
    //@ assert (3 * n) * n <= 30000;

    ans = 3 * n * n;
    return ans;
}
