#include <stdint.h>
#include <stdbool.h>

/*@ predicate valid_params(integer n, integer k) =
      n >= 1 && n <= 100000 &&
      k >= 1 && k <= 500;

   predicate valid_array(integer n, uint64_t *h) =
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

/*@
  requires valid_params(n, k);
  requires \valid(h + (0 .. n-1));
  requires valid_array(n, h);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
uint64_t func(uint64_t n, uint64_t k, uint64_t *h) {
    uint64_t ans = 0;
    uint64_t index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant ans <= index;
      loop assigns ans, index;
      loop variant n - index;
    */
    while (index < n) {
        uint64_t hi = h[index];
        
        //@ assert hi >= 1 && hi <= 500;
        
        if (hi >= k) {
            ans = ans + 1;
        }
        
        index = index + 1;
    }
    
    return ans;
}
