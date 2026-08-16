#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
    ensures \result >= (100 * ((n) - (m)) + 1900 * (m));
    ensures \result <= (100 * ((n) - (m)) + 1900 * (m)) + (100 * (m));
*/
int32_t func(uint32_t n, uint32_t m) {
    int32_t ans;
    uint32_t shift;
    int32_t extra;
    uint32_t i;

    ans = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    shift = (n >= m) ? (n - m) : 0;
    extra = 0;
    i = 0;

    /*@
        loop invariant 0 <= i <= m;
        loop invariant extra >= 0;
        loop invariant extra <= 100 * (int32_t)i;
        loop invariant ans == 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
        loop invariant i <= shift + m;
        loop assigns i, extra;
        loop variant m - i;
    */
    while (i < m) {
        //@ assert i < m;
        if (i < shift) {
            extra += 100;
        }
        i += 1;
    }

    ans += extra;
    //@ assert ans >= (100 * ((n) - (m)) + 1900 * (m));
    return ans;
}
