#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_h(int *h, integer n) =
      \forall integer j; 0 <= j < n ==> (1 <= h[j] && h[j] <= 500);
*/

/*@ predicate is_valid_params(integer n, integer m, integer k) =
      1 <= n && n <= 100000 &&
      1 <= m && m <= 100000 &&
      1 <= k && k <= 500;
*/

/*@ lemma ans_bounds:
      \forall integer n, int *h, integer k;
      is_valid_params(n, 100000, k) && is_valid_h(h, n) ==>
      (\forall integer i, integer ans;
       0 <= i <= n && 0 <= ans <= i ==>
       ans <= n);
*/


int func(int n, int m, int *h, int k) {
    int ans = 0;
    int i = 0;
    
    
    while (i < n) {
        int hi = h[i];
        //@ assert 1 <= hi <= 500;
        if (hi >= k) {
            ans += 1;
        }
        i += 1;
    }
    //@ assert i == n;
    //@ assert 0 <= ans <= n;
    return ans;
}
