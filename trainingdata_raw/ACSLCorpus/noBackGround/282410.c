#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
    ensures \result >= (100 * ((n) - (m)) + 1900 * (m));
    ensures \result <= (100 * ((n) - (m)) + 1900 * (m)) * 2;
*/
int32_t func(uint32_t n, uint32_t m) {
    int32_t ans;
    uint32_t i;

    //@ assert (1 <= (n) <= 100 &&         1 <= (m) <= (n) &&         (m) <= 5);
    ans = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    i = 1;

    /*@
        loop invariant 1 <= i <= m;
        loop invariant ans >= (100 * ((n) - (m)) + 1900 * (m));
        loop invariant ans <= (100 * ((n) - (m)) + 1900 * (m)) * 2;
        loop invariant ans <= (100 * ((n) - (m)) + 1900 * (m)) + 100 * (int32_t)i * 2;
        loop assigns ans, i;
        loop variant m - i;
    */
    while (i < m) {
        //@ assert 1 <= i <= m;
        if (i * 2 + 1 <= m) {
            ans += 100 * (int32_t)i;
        } else {
            ans += 100 * ((int32_t)m - (int32_t)i);
        }
        i += 1;
    }

    //@ assert ans >= (100 * ((n) - (m)) + 1900 * (m));
    //@ assert ans <= (100 * ((n) - (m)) + 1900 * (m)) * 2;
    return ans;
}
