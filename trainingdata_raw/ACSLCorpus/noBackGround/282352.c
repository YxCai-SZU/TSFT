#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
    ensures \result >= 100 * (n - m) + 1900 * m;
    ensures \result <= 1900 * n;
*/
int32_t func(uint32_t n, uint32_t m) {
    int32_t ans = 0;
    uint32_t i = 0;
    uint32_t j = 0;

    /*@
        loop invariant 0 <= i <= m;
        loop invariant ans >= 0;
        loop invariant ans <= 1900 * i;
        loop invariant ans == 1900 * i;
        loop assigns ans, i;
    */
    while (i < m) {
        //@ assert ans == 1900 * i;
        ans += 1900;
        i += 1;
        //@ assert ans == 1900 * i;
    }

    /*@
        loop invariant 0 <= j <= n - m;
        loop invariant ans >= 1900 * m;
        loop invariant ans <= 1900 * n;
        loop invariant ans == 1900 * m + 100 * j;
        loop assigns ans, j;
    */
    while (j < n - m) {
        //@ assert ans == 1900 * m + 100 * j;
        ans += 100;
        j += 1;
        //@ assert ans == 1900 * m + 100 * j;
    }

    //@ assert ans == 1900 * m + 100 * (n - m);
    return ans;
}
