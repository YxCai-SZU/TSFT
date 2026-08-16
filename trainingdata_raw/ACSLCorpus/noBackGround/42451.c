#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 1000000000 &&
        1 <= (b) && (b) <= 1000000000 &&
        1 <= (c) && (c) <= 1000000000 &&
        1 <= (k) && (k) <= 1000000000 &&
        (a) + (b) + (c) >= (k));
    ensures \result <= k;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    uint32_t a_cnt;
    uint32_t k_cnt;
    uint32_t b_cnt;
    uint32_t c_cnt;
    uint32_t res;

    //@ assert (1 <= (a) && (a) <= 1000000000 &&         1 <= (b) && (b) <= 1000000000 &&         1 <= (c) && (c) <= 1000000000 &&         1 <= (k) && (k) <= 1000000000 &&         (a) + (b) + (c) >= (k));

    if (k < a) {
        a_cnt = k;
    } else {
        a_cnt = a;
    }

    k_cnt = k - a_cnt;

    if (k_cnt < b) {
        b_cnt = k_cnt;
    } else {
        b_cnt = b;
    }

    k_cnt = k_cnt - b_cnt;

    if (k_cnt < c) {
        c_cnt = k_cnt;
    } else {
        c_cnt = c;
    }

    k_cnt = k_cnt - c_cnt;

    res = a_cnt - k_cnt;

    //@ assert res <= k;

    return res;
}
