#include <stddef.h>
#include <stdint.h>

/*@ predicate valid_params(integer n, integer k) =
      n >= 1 && n <= 100000 &&
      k >= 1 && k <= 500;
*/

/*@ predicate valid_array(int *h, integer n) =
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

/*@ lemma ans_bounds:
      \forall integer ans, integer index, integer n;
      ans >= 0 && ans <= index && index <= n ==> ans <= n;
*/

/*@
  requires valid_params(n, k);
  requires valid_array(h, n);
  requires \valid(h + (0 .. n-1));
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= (int)n;
*/
int func(size_t n, size_t k, int *h) {
    int ans = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant ans >= 0;
        loop invariant ans <= (int)index;
        loop invariant ans <= (int)n;
        loop invariant valid_array(h, n);
        loop assigns ans, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert index < n;
        
        if ((size_t)k <= (size_t)h[index]) {
            ans += 1;
        }
        index += 1;
        
        //@ assert ans <= (int)n;
    }
    
    return ans;
}
