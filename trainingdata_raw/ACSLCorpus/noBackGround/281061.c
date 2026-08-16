#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 0 <= (m) <= (n) * (n));
    ensures \result == ((n) * (n) - (m));
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    // Variable declarations at top of scope
    int64_t nn;
    int64_t res;

    //@ assert n * n <= 10000;
    nn = n * n;
    //@ assert 0 <= m && m <= n * n;
    //@ assert nn == n * n;
    res = nn - m;
    return res;
}
