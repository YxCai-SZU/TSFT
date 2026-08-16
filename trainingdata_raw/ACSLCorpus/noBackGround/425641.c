#include <limits.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        (k) >= 1 &&
        (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) <= 2000000000);
    ensures \result <= a;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c, int k) {
    int a_cnt = a;
    int k_cnt = k;
    int ans = 0;

    //@ assert a_cnt >= 0 && k_cnt >= 1;
    if (a_cnt >= k_cnt) {
        ans += k_cnt;
    } else {
        ans += a_cnt;
    }
    k_cnt -= a_cnt;
    a_cnt = 0;

    //@ assert ans >= 0 && ans <= a;
    int b_cnt = b;
    if (k_cnt >= b_cnt) {
        k_cnt -= b_cnt;
        b_cnt = 0;
    } else {
        b_cnt -= k_cnt;
        k_cnt = 0;
    }

    //@ assert ans <= a;
    int c_cnt = c;
    if (k_cnt >= c_cnt) {
        c_cnt -= k_cnt;
        k_cnt = 0;
    } else {
        c_cnt = 0;
        k_cnt = 0;
    }

    //@ assert ans <= a;
    return ans;
}
