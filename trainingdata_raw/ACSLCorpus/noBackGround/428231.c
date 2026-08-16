#include <stdint.h>
/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == a + c || \result == a + d || \result == b + c || \result == b + d;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t max_ab;
    uint32_t max_cd;
    uint32_t ans;

    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);

    if (a > b) {
        max_ab = a;
    } else {
        max_ab = b;
    }
    //@ assert max_ab == (((a) > (b)) ? (a) : (b));

    if (c > d) {
        max_cd = c;
    } else {
        max_cd = d;
    }
    //@ assert max_cd == (((c) > (d)) ? (c) : (d));

    //@ assert max_ab >= a;
    //@ assert max_ab >= b;
    //@ assert max_cd >= c;
    //@ assert max_cd >= d;

    //@ assert max_ab + max_cd >= a + c;
    //@ assert max_ab + max_cd >= a + d;
    //@ assert max_ab + max_cd >= b + c;
    //@ assert max_ab + max_cd >= b + d;

    if (max_ab > max_cd) {
        ans = max_ab + max_cd;
    } else {
        ans = max_cd + max_ab;
    }

    //@ assert ans == max_ab + max_cd;
    return ans;
}
