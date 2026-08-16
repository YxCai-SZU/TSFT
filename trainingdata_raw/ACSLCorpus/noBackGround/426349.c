#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100000000000000000 &&
        0 <= (b) && (b) <= 100000000000000000 &&
        0 <= (c) && (c) <= 100000000000000000 &&
        1 <= (k) && (k) <= 100000000000000000 &&
        (a) + (b) + (c) >= (k));
    ensures \result >= 0;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k) {
    int64_t ans = 0;
    int64_t cnt = 0;
    int64_t ans2 = 0;
    int64_t cnt2 = 0;

    if (a < k) {
        ans += a;
        cnt += a;
    } else {
        ans += k;
        cnt += k;
    }

    //@ assert ans >= 0;
    //@ assert cnt >= 0;

    if (cnt >= k) {
        //@ assert ans >= 0;
        return ans;
    }

    if (a + b < k) {
        //@ assert ans >= 0;
        return ans;
    }

    if (a + b == k) {
        ans += k - cnt;
        //@ assert ans >= 0;
        return ans;
    }

    cnt2 += k - a;
    ans2 += k - a;

    //@ assert ans2 >= 0;
    //@ assert cnt2 >= 0;

    if (cnt2 >= k) {
        //@ assert ans + ans2 >= 0;
        return ans + ans2;
    }

    if (a + b < k) {
        //@ assert ans + ans2 >= 0;
        return ans + ans2;
    }

    if (a + b == k) {
        ans2 += k - cnt2;
        //@ assert ans + ans2 >= 0;
        return ans + ans2;
    }

    //@ assert ans + ans2 >= 0;
    return ans + ans2;
}
