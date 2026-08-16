#include <stdbool.h>
#include <stdint.h>

/*@
  requires 1 <= n <= 100000;
  requires 1 <= k <= 500;
  requires \valid(h + (0 .. n-1));
  requires (\forall integer j; 0 <= j < (n) ==> 1 <= (h)[j] <= 500);
  assigns \nothing;
  ensures \result <= n;
*/
uint32_t func(uint32_t n, uint32_t k, int32_t *h) {
    uint32_t ans = 0;
    uint32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= ans <= i;
      loop invariant \forall integer j; 0 <= j < i ==> 1 <= h[j] <= 500;
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] >= k) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
