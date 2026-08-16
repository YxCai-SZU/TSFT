#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_array(int64_t *arr, size_t n) =
        n > 0 && n <= 100000 &&
        \valid(arr + (0 .. n-1)) &&
        \forall size_t i; 0 <= i < n ==> 1 <= arr[i] && arr[i] <= 1000000000;

    logic integer max(integer a, integer b) = a > b ? a : b;
*/

/*@
    requires valid_array(h, n);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int64_t func(size_t n, int64_t *h) {
    int64_t cur = 0;
    int64_t bound = 0;
    int64_t res = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= n-1;
        loop invariant valid_array(h, n);
        loop invariant 0 <= cur <= i;
        loop invariant 0 <= res <= i;
        loop invariant 0 <= bound;
        loop assigns i, cur, bound, res;
        loop variant n - i;
    */
    while (i < n - 1) {
        if (bound <= h[i]) {
            cur = cur + 1;
            if (res < cur) {
                res = cur;
            }
        } else {
            cur = 0;
        }

        if (bound < h[i + 1]) {
            bound = h[i + 1];
        }

        i = i + 1;
    }

    return res;
}
