#include <stdint.h>
#include <stddef.h>

/*@ predicate valid_range(int64_t *arr, integer n) =
      n >= 1 && n <= 200000 &&
      \forall integer i; 0 <= i < n ==> arr[i] >= 1 && arr[i] <= 1000000000;
*/

/*@ predicate loop_inv(int64_t *xs, integer n, integer cur, int32_t ans, uint64_t prev_height) =
      cur >= 0 && cur <= n &&
      ans >= 0 && ans <= (int32_t)cur &&
      prev_height >= 0 && prev_height <= 1000000000 &&
      \forall integer i; 0 <= i < cur ==> xs[i] >= 1 && xs[i] <= 1000000000 &&
      n >= 1 && n <= 200000 &&
      \forall integer k; 0 <= k < n ==> xs[k] >= 1 && xs[k] <= 1000000000;
*/

/*@ lemma prev_height_bound:
      \forall int64_t *xs, integer n, integer cur, int32_t ans, uint64_t prev_height;
      loop_inv(xs, n, cur, ans, prev_height) ==> prev_height <= 1000000000;
*/

/*@ requires n >= 1 && n <= 200000;
    requires \valid(xs + (0 .. n-1));
    requires valid_range(xs, n);
    ensures \result >= 0 || \result == -1;
    ensures \result >= 0 ==> \result <= n;
*/
int32_t func(size_t n, int64_t *xs) {
    int32_t ans = 0;
    uint64_t prev_height = 0;
    size_t cur = 0;

    /*@ loop invariant loop_inv(xs, n, cur, ans, prev_height);
        loop assigns ans, prev_height, cur;
        loop variant n - cur;
    */
    while (cur < n) {
        uint64_t h = xs[cur];
        if (prev_height > h) {
            ans += 1;
            prev_height = h;
        } else {
            prev_height = h;
        }
        cur += 1;
        //@ assert prev_height <= 1000000000;
    }
    return ans;
}
