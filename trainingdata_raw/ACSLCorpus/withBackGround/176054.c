#include <stddef.h>
#include <stdint.h>

/*@ predicate is_valid_array(int64_t *p, size_t n) =
      n >= 1 && n <= 200000 &&
      \forall size_t i; 0 <= i < n ==> p[i] >= 1 && p[i] <= (int64_t)n &&
      \forall size_t i, j; 0 <= i < j < n ==> p[i] != p[j];
*/

/*@ lemma ans_range: \forall integer i, ans; 1 <= i && 1 <= ans <= i ==> ans >= 1 && ans <= i;
*/

/*@
  requires \valid(p + (0 .. n-1));
  requires is_valid_array(p, n);
  assigns \nothing;
  ensures 1 <= \result <= (int32_t)n;
*/
int32_t func(size_t n, int64_t *p) {
    int32_t ans = 1;
    int64_t min_bound = p[0];
    size_t i = 1;

    /*@
      loop invariant 1 <= i <= n;
      loop invariant 1 <= ans <= (int32_t)i;
      loop invariant min_bound <= p[0];
      loop invariant \forall size_t k; 0 <= k < i ==> p[k] >= 1 && p[k] <= (int64_t)n;
      loop invariant \forall size_t k, l; 0 <= k < l < i ==> p[k] != p[l];
      loop invariant min_bound >= 1 && min_bound <= (int64_t)n;
      loop assigns i, ans, min_bound;
      loop variant n - i;
    */
    while (i < n) {
        int64_t pi = p[i];
        //@ assert pi >= 1 && pi <= (int64_t)n;
        if (min_bound > pi) {
            ans += 1;
            min_bound = pi;
        }
        i += 1;
    }
    return ans;
}
