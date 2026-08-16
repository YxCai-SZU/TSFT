#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(int64_t *arr, size_t len) =
        len > 0 && len <= 100000 &&
        \valid(arr + (0 .. len-1)) &&
        \forall size_t i; 0 <= i < len ==> 1 <= arr[i] <= 1000000000;
*/

/*@
    logic integer max(integer a, integer b) = (a > b) ? a : b;
*/

/*@
    lemma max_property:
        \forall integer a, b; max(a, b) >= a && max(a, b) >= b;
*/

/*@
    requires valid_array(h, n);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(size_t n, const int64_t *h) {
    int64_t cur = 0;
    int64_t highest = -1;
    size_t skip = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n-1;
        loop invariant 0 <= cur <= (int64_t)i;
        loop invariant 0 <= skip <= i;
        loop invariant highest >= -1;
        loop invariant valid_array(h, n);
        loop assigns i, cur, highest, skip;
        loop variant n - i;
    */
    while (i < n - 1) {
        if (h[i] < h[i + 1]) {
            highest = (highest > h[i]) ? highest : h[i];
            skip = 0;
        } else {
            if (h[i] > highest) {
                highest = h[i];
            } else {
                cur += 1;
                skip += 1;
            }
        }
        i += 1;
    }
    return cur;
}
