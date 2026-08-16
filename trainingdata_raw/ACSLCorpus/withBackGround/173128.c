#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_params(size_t n, int *v) =
      n >= 2 && n <= 100000 &&
      \valid(v + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> v[i] >= 1 && v[i] <= 1000000000;
*/

/*@ predicate loop_invariant(size_t n, int *v, size_t m, int ans) =
      0 <= m && m <= n-1 &&
      0 <= ans && ans <= n - m &&
      valid_params(n, v);
*/

/*@
  requires valid_params(n, v);
  ensures \result >= 0 && \result <= n;
*/
int func(size_t n, int *v) {
    size_t m;
    int x;
    int ans;
    
    m = n - 1;
    x = v[m];
    ans = 0;
    
    /*@
      loop invariant loop_invariant(n, v, m, ans);
      loop assigns m, x, ans;
      loop variant m;
    */
    while (m > 0) {
        m -= 1;
        if (v[m] < x) {
            ans += 1;
            x = v[m];
        }
    }
    return ans;
}
