#include <stdbool.h>

/*@
    requires (0 <= (a) <= 100 &&
        0 <= (b) <= 100 &&
        0 <= (c) <= 100 &&
        1 <= (k) <= 100);
    ensures \result <= k;
    ensures \result >= -k;
    assigns \nothing;
*/
long func(long a, long b, long c, long k)
{
    bool a_is_zero = false;
    bool b_is_zero = false;
    bool c_is_zero = false;
    long ans = 0;
    long rst = k;

    //@ assert (0 <= (a) <= 100 &&         0 <= (b) <= 100 &&         0 <= (c) <= 100 &&         1 <= (k) <= 100);

    if (a > rst) {
        ans += rst;
        rst -= rst;
        //@ assert ans <= k;
    } else {
        ans += a;
        rst -= a;
        a_is_zero = true;
        //@ assert ans <= k;
    }

    if (b > rst) {
        rst -= rst;
    } else {
        rst -= b;
        b_is_zero = true;
    }

    if (c > rst) {
        ans -= rst;
        rst -= rst;
        //@ assert ans >= -k;
    } else {
        ans -= c;
        rst -= c;
        c_is_zero = true;
        //@ assert ans >= -k;
    }

    if (a_is_zero && b_is_zero && c_is_zero) {
        ans += rst;
    }

    //@ assert ans <= k;
    //@ assert ans >= -k;

    return ans;
}
