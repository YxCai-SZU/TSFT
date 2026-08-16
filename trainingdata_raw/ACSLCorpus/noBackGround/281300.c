#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= 3);
    ensures \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans = 0;
    int r = k;

    //@ assert 1 <= r && r <= 3;

    if (a < r) {
        ans += a;
        r -= a;
    } else {
        ans += r;
        r = 0;
    }

    if (r > 0) {
        //@ assert r <= 3;
        //@ assert b >= 1;
        r -= b;
    }

    if (r > 0) {
        ans -= r;
    }

    //@ assert ans <= a;
    return ans;
}
