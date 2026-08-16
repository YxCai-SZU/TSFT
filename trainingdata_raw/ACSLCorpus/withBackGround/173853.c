#include <stddef.h>
#include <stdint.h>

/*@ predicate valid_params(size_t N, int64_t *H) =
      N > 0 && N <= 100000 &&
      \valid(H + (0 .. N-1)) &&
      \forall integer j; 0 <= j < N ==> H[j] >= 1 && H[j] <= 1000000000;
*/

/*@ logic integer max_value(integer a, integer b) =
      a > b ? a : b;
*/

/*@ lemma count_bounds:
      \forall integer i, integer cnt;
      0 <= i && 0 <= cnt && cnt <= i ==> 0 <= cnt;
*/

/*@ lemma max_bounds:
      \forall integer i, integer m;
      0 <= i && 0 <= m && m <= i ==> 0 <= m;
*/

/*@
  requires valid_params(N, H);
  assigns \nothing;
  ensures \result >= 0;
*/
int64_t func(size_t N, int64_t *H) {
    int64_t max = 0;
    int64_t count = 0;
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= N;
      loop invariant 0 <= count <= i;
      loop invariant 0 <= max <= i;
      loop invariant \forall integer k; 0 <= k < i ==> H[k] >= 1 && H[k] <= 1000000000;
      loop assigns i, count, max;
      loop variant N - i;
    */
    while (i < N - 1) {
        if (H[i] >= H[i + 1]) {
            count += 1;
            if (count > max) {
                max = count;
            }
        } else {
            count = 0;
        }
        i += 1;
    }

    return max;
}
