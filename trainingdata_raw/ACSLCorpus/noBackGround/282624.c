#include <limits.h>

/*@
    requires ((A) >= 0 && (B) >= 0 && (C) >= 0 &&
        (K) >= 1 &&
        (K) <= (A) + (B) + (C) &&
        (A) + (B) + (C) <= 2000000000);
    ensures \result <= K;
*/
int func(int A, int B, int C, int K)
{
    int ans = 0;
    int rst = K;
    int min_a_rst;
    int min_b_rst;
    int min_c_rst;

    //@ assert ((A) >= 0 && (B) >= 0 && (C) >= 0 &&         (K) >= 1 &&         (K) <= (A) + (B) + (C) &&         (A) + (B) + (C) <= 2000000000);
    //@ ghost int original_K = K;

    if (A < rst) {
        min_a_rst = A;
    } else {
        min_a_rst = rst;
    }
    //@ assert min_a_rst == ((A) < (rst) ? (A) : (rst));
    ans += min_a_rst;
    rst -= min_a_rst;
    //@ assert rst == original_K - min_a_rst;

    if (B < rst) {
        min_b_rst = B;
    } else {
        min_b_rst = rst;
    }
    //@ assert min_b_rst == ((B) < (rst) ? (B) : (rst));
    rst -= min_b_rst;
    //@ assert rst == original_K - min_a_rst - min_b_rst;

    if (C < rst) {
        min_c_rst = C;
    } else {
        min_c_rst = rst;
    }
    //@ assert min_c_rst == ((C) < (rst) ? (C) : (rst));
    rst -= min_c_rst;
    //@ assert rst == original_K - min_a_rst - min_b_rst - min_c_rst;

    ans -= rst;
    //@ assert ans == min_a_rst - rst;
    //@ assert ans <= original_K;
    return ans;
}
