#include <stddef.h>
#include <stdbool.h>

/*@
    predicate valid_h(integer len, int *h) =
        len >= 1 && len <= 100000 &&
        \forall integer i; 0 <= i < len ==> h[i] >= 1 && h[i] <= 500;

    predicate loop_invariant(integer i, integer ans, integer len, int *h, integer k) =
        0 <= i <= len &&
        ans <= i &&
        valid_h(len, h) &&
        k >= 1 && k <= 100000 &&
        ans <= len;
*/

/*@
    requires k >= 1 && k <= 100000;
    requires \valid(h + (0..len-1));
    requires valid_h(len, h);
    assigns \nothing;
    ensures 0 <= \result <= len;
    ensures valid_h(len, h);
*/
size_t func(size_t k, int *h, size_t len) {
    size_t ans = 0;
    size_t i = 0;

    /*@
        loop invariant loop_invariant(i, ans, len, h, k);
        loop assigns i, ans;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert loop_invariant(i, ans, len, h, k);
        if (h[i] >= (int)k) {
            ans += 1;
        }
        i += 1;
    }
    //@ assert ans <= len;
    return ans;
}
