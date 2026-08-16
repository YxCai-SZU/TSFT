#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_h(unsigned int *h, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= h[i] <= 500;
*/

/*@ predicate ans_bounds(integer ans, integer n) =
      0 <= ans <= n;
*/

/*@ lemma ans_monotonic:
      \forall integer ans, integer index, integer n;
      0 <= index <= n && 0 <= ans <= index ==> 0 <= ans <= n;
*/

/*@
  requires 1 <= n <= 100000;
  requires \valid(h + (0 .. n-1));
  requires valid_h(h, n);
  requires 1 <= k <= 500;
  assigns \nothing;
  ensures ans_bounds(\result, n);
*/
unsigned int func(unsigned int k, size_t n, unsigned int *h) {
    unsigned int ans = 0;
    size_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant ans_bounds(ans, index);
      loop assigns ans, index;
      loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        if (h[index] >= k) {
            ans += 1;
        }
        index += 1;
    }
    return ans;
}
