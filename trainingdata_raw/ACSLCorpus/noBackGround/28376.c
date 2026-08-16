#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= (a) + (b) + (c) &&
        (a) + (b) >= (k));
    ensures 1 <= \result && \result <= k;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k) {
    int32_t ans = 1;
    uint32_t i = 1;

    /*@
        loop invariant 1 <= i && i <= k;
        loop invariant 1 <= ans && ans <= i;
        loop assigns i, ans;
        loop variant k - i;
    */
    while (i < k) {
        //@ assert 1 <= i && i < k;
        if (i < a) {
            ans += 1;
        } else if (i < a + b) {
            // pass
        } else {
            ans -= 1;
        }
        i += 1;
    }
    return ans;
}
