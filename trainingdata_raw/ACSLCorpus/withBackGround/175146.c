#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c, integer k) =
        0 <= a <= 1000000000 &&
        0 <= b <= 1000000000 &&
        0 <= c <= 1000000000 &&
        1 <= k <= 1000000000 &&
        a + b + c >= k;

    predicate output_bounds(integer res, integer a, integer c) =
        res >= -c && res <= a;
*/

/*@
    requires valid_input(a, b, c, k);
    ensures output_bounds(\result, a, c);
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k) {
    int32_t k_local;
    int32_t ans;
    int32_t p;

    k_local = k;
    ans = 0;
    p = 0;

    if (a >= k_local) {
        ans += k_local;
        p = k_local;
        k_local = 0;
    } else {
        ans += a;
        p = a;
        k_local -= a;
    }

    if (b >= k_local) {
        p = p + k_local;
        k_local = 0;
    } else {
        p = p + b;
        k_local -= b;
    }

    ans -= k_local;

    //@ assert ans >= -c && ans <= a;
    return ans;
}
