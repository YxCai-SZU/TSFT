#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_h_array(int64_t *h, size_t len) =
        len > 0 && len <= 100000 &&
        \forall size_t j; 0 <= j < len ==> 1 <= h[j] && h[j] <= 500;

    predicate loop_invariant(int64_t *h, size_t len, size_t i, int64_t res, size_t k) =
        0 <= i && i <= len &&
        res >= 0 && res <= (int64_t)i &&
        \forall size_t j; 0 <= j < i ==> 1 <= h[j] && h[j] <= 500 &&
        k > 0 && k <= 100000 &&
        valid_h_array(h, len);
*/

/*@
    requires k > 0 && k <= 100000;
    requires \valid(h + (0 .. len-1));
    requires valid_h_array(h, len);
    assigns \nothing;
    ensures \result >= 0 && \result <= (int64_t)len;
*/
int64_t func(size_t k, int64_t *h, size_t len) {
    int64_t res = 0;
    size_t i = 0;

    /*@
        loop invariant loop_invariant(h, len, i, res, k);
        loop assigns i, res;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i && i < len;
        if (h[i] >= (int64_t)k) {
            res += 1;
        }
        i += 1;
    }
    return res;
}
