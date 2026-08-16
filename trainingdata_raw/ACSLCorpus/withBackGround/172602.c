#include <stdint.h>

/*@
    predicate valid_params(integer a, integer b, integer c, integer k) =
        0 <= a && a <= 1000000000 &&
        0 <= b && b <= 1000000000 &&
        0 <= c && c <= 1000000000 &&
        1 <= k && k <= 1000000000000000000 &&
        a + b + c >= k;

    predicate result_bounds(integer res, integer a, integer c) =
        res >= -c && res <= a;
*/

/*@
    requires valid_params(a, b, c, k);
    ensures result_bounds(\result, a, c);
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t k_remaining;
    int64_t a_m;
    int64_t b_m;
    int64_t c_m;
    int64_t res;

    k_remaining = k;

    //@ assert k_remaining >= 0;

    if (a < k_remaining) {
        a_m = a;
    } else {
        a_m = k_remaining;
    }
    //@ assert a_m >= 0 && a_m <= a;

    k_remaining = k_remaining - a_m;
    //@ assert k_remaining >= 0;

    if (b < k_remaining) {
        b_m = b;
    } else {
        b_m = k_remaining;
    }
    //@ assert b_m >= 0 && b_m <= b;

    k_remaining = k_remaining - b_m;
    //@ assert k_remaining >= 0;

    if (c < k_remaining) {
        c_m = c;
    } else {
        c_m = k_remaining;
    }
    //@ assert c_m >= 0 && c_m <= c;

    k_remaining = k_remaining - c_m;
    //@ assert k_remaining >= 0;

    //@ assert a_m + b_m + c_m <= a + b + c;
    //@ assert a_m + b_m + c_m >= k;

    res = a_m - c_m;
    //@ assert res >= -c && res <= a;

    return res;
}
