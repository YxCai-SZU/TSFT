#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_array(int64_t n, int64_t *a) =
      n >= 1 && n <= 200000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000000;
*/

/*@ predicate valid_params(int64_t n, int64_t k) =
      n >= 1 && n <= 200000 && k >= 1 && k <= 200000;
*/

/*@ lemma remainder_bounds:
      \forall int64_t k, value, remainder;
      remainder >= 0 && remainder <= k && value >= 1 && value <= 1000000000 && remainder >= value ==>
      remainder - value >= 0 && remainder - value <= k;
*/

/*@
  requires valid_params(n, k);
  requires valid_array(n, a);
  ensures \result >= 0 && \result <= n;
*/
int64_t func(int64_t n, int64_t k, int64_t *a) {
    int64_t count = 0;
    int64_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop invariant valid_array(n, a);
      loop invariant valid_params(n, k);
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        int64_t remainder = k;
        int64_t index = i;
        int64_t value = a[index];
        
        /*@
          loop invariant 0 <= remainder <= k;
          loop invariant 0 <= index < n;
          loop invariant valid_array(n, a);
          loop invariant valid_params(n, k);
          loop assigns remainder;
          loop variant remainder;
        */
        while (remainder >= value) {
            remainder -= value;
        }
        
        if (remainder == 0) {
            count += 1;
        }
        
        i += 1;
    }
    
    return count;
}
