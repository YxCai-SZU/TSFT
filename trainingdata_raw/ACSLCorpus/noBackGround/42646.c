#include <limits.h>
#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 1000000000 &&
        0 <= (b) && (b) <= 1000000000 &&
        0 <= (c) && (c) <= 1000000000 &&
        1 <= (k) && (k) <= 1000000000 &&
        (k) <= (a) + (b) + (c));
    ensures \result >= -c && \result <= a;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t res = 0;
    int64_t rst = k;
    int64_t min_a_rst;
    int64_t min_b_rst;
    int64_t min_c_rst;

    //@ assert (0 <= (a) && (a) <= 1000000000 &&         0 <= (b) && (b) <= 1000000000 &&         0 <= (c) && (c) <= 1000000000 &&         1 <= (k) && (k) <= 1000000000 &&         (k) <= (a) + (b) + (c));

    // Implementing min function manually
    //@ ghost int64_t old_rst = rst;
    if (a < rst) {
        min_a_rst = a;
    } else {
        min_a_rst = rst;
    }
    res += min_a_rst;
    rst -= min_a_rst;

    //@ assert min_a_rst == (((a) < (old_rst)) ? (a) : (old_rst));
    //@ assert rst == old_rst - min_a_rst;

    // Implementing min function manually
    //@ ghost old_rst = rst;
    if (b < rst) {
        min_b_rst = b;
    } else {
        min_b_rst = rst;
    }
    rst -= min_b_rst;

    //@ assert min_b_rst == (((b) < (old_rst)) ? (b) : (old_rst));
    //@ assert rst == old_rst - min_b_rst;

    // Implementing min function manually
    //@ ghost old_rst = rst;
    if (c < rst) {
        min_c_rst = c;
    } else {
        min_c_rst = rst;
    }
    res -= min_c_rst;

    //@ assert min_c_rst == (((c) < (old_rst)) ? (c) : (old_rst));
    //@ assert res == min_a_rst - min_c_rst;

    //@ assert res >= -c;
    //@ assert res <= a;

    return res;
}
