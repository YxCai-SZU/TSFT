#include <stdint.h>
#include <limits.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && (k) >= 1);
    requires ((k) <= (a) + (b) + (c) && (a) + (b) + (c) <= INT64_MAX);
    ensures \result <= k;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans = 0;
    int64_t rst = k;

    //@ assert rst == k;

    if (a >= rst) {
        ans += rst;
        rst -= rst;
    } else {
        ans += a;
        rst -= a;
    }

    //@ assert ans <= k;

    if (b >= rst) {
        rst -= rst;
    } else {
        rst -= b;
    }

    //@ assert ans <= k;

    ans -= rst;

    //@ assert ans <= k;

    return ans;
}
