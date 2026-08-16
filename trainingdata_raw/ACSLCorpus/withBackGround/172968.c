#include <stddef.h>

/*@
    predicate valid_params(size_t k, size_t len) =
        k >= 1 && k <= 500 &&
        len >= 1 && len <= 100000;

    predicate valid_array(size_t *h, size_t len) =
        \forall size_t i; 0 <= i < len ==> 1 <= h[i] && h[i] <= 500;

    logic integer count_ge_k(size_t *h, size_t k, integer n) =
        n <= 0 ? 0 :
        (h[n-1] >= k ? 1 : 0) + count_ge_k(h, k, n-1);
*/

/*@
    requires valid_params(k, len);
    requires valid_array(h, len);
    requires \valid(h + (0 .. len-1));
    assigns \nothing;
    ensures 0 <= \result <= len;
    ensures \result == count_ge_k(h, k, (integer)len);
*/
size_t func(size_t k, size_t *h, size_t len) {
    size_t ans = 0;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= len;
        loop invariant 0 <= ans <= index;
        loop invariant ans == count_ge_k(h, k, (integer)index);
        loop assigns ans, index;
        loop variant len - index;
    */
    while (index < len) {
        //@ assert valid_array(h, len);
        if (h[index] >= k) {
            ans += 1;
        }
        index += 1;
    }
    return ans;
}
