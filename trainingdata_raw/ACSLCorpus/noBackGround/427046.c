#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d)
{
    int64_t ans = 0;
    int64_t con = 0;
    int64_t con2 = 0;
    int64_t b_abs;
    int64_t d_abs;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);

    if (b < 0) {
        b_abs = -b;
    } else {
        b_abs = b;
    }

    if (d < 0) {
        d_abs = -d;
    } else {
        d_abs = d;
    }

    //@ assert b_abs >= 0 && d_abs >= 0;

    if (a >= con && con >= 0) {
        ans += 1;
        con += b_abs;
    }

    //@ assert ans >= 0;

    if (con + b_abs >= c && con + b_abs <= c + d_abs) {
        ans += 1;
        con2 += b_abs;
    }

    //@ assert ans >= 0;

    if (con2 + b_abs >= c && con2 + b_abs <= c + d_abs) {
        ans += 1;
    }

    //@ assert ans >= 0;
    return ans;
}
