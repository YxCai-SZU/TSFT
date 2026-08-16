#include <stdint.h>
#include <stdbool.h>

/*@ predicate valid_array(uint32_t *a, integer n) =
      n > 0 && n <= 100000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> a[i] > 0 && a[i] <= 1000000000;
*/

/*@ predicate ans_bounds(integer ans, integer idx, integer n) =
      ans >= 0 && ans <= idx && idx <= n;
*/

/*@ lemma ans_final_bound: \forall integer ans, integer n;
      ans_bounds(ans, n, n) ==> ans >= 0 && ans <= n;
*/

/*@ requires valid_array(H, N);
    ensures \result >= 0 && \result <= N;
    assigns \nothing;
*/
uint32_t func(uint32_t N, uint32_t *H) {
    uint32_t max = 0;
    uint32_t ans = 0;
    uint32_t index = 0;

    /*@ loop invariant 0 <= index <= N;
        loop invariant ans_bounds(ans, index, N);
        loop invariant \forall integer i; 0 <= i < N ==> H[i] > 0 && H[i] <= 1000000000;
        loop invariant max == 0 || \exists integer j; 0 <= j < index && H[j] == max;
        loop assigns max, ans, index;
        loop variant N - index;
    */
    while (index < N) {
        uint32_t h = H[index];
        //@ assert h > 0 && h <= 1000000000;
        if (max <= h) {
            ans += 1;
            max = h;
        }
        index += 1;
    }
    return ans;
}
