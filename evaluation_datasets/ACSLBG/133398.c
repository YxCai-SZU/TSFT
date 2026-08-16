#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b, integer c, integer d) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100 && 1 <= d <= 100;

    predicate result_range(integer r) = 1 <= r <= 4;
*/


int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    int32_t a_cnt = 0;
    int32_t b_cnt = 0;
    int32_t c_cnt = 0;
    int32_t d_cnt = 0;
    int32_t a_cnt2;
    int32_t b_cnt2;
    int32_t c_cnt2;
    int32_t d_cnt2;
    int32_t result;

    if (a < b) {
        a_cnt += 1;
    } else {
        b_cnt += 1;
    }
    if (c < d) {
        c_cnt += 1;
    } else {
        d_cnt += 1;
    }

    a_cnt2 = a_cnt;
    b_cnt2 = b_cnt;
    c_cnt2 = c_cnt;
    d_cnt2 = d_cnt;

    if (a_cnt2 > b_cnt2) {
        b_cnt2 += 1;
    } else {
        a_cnt2 += 1;
    }
    if (c_cnt2 > d_cnt2) {
        d_cnt2 += 1;
    } else {
        c_cnt2 += 1;
    }

    result = 0;
    if (a_cnt2 > b_cnt2 && a_cnt2 > c_cnt2 && a_cnt2 > d_cnt2) {
        result = 1;
    } else if (b_cnt2 > a_cnt2 && b_cnt2 > c_cnt2 && b_cnt2 > d_cnt2) {
        result = 2;
    } else if (c_cnt2 > a_cnt2 && c_cnt2 > b_cnt2 && c_cnt2 > d_cnt2) {
        result = 3;
    } else {
        result = 4;
    }

    //@ assert result >= 1;
    //@ assert result <= 4;

    return result;
}
