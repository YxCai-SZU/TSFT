#include <stdbool.h>
#include <stddef.h>

/*@ predicate heights_in_range(int *heights, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= heights[i] <= 500;
*/

/*@ predicate valid_params(integer n, integer k) =
      n >= 1 && n <= 100000 && k >= 1 && k <= 500;
*/

/*@ lemma ans_bounds:
      \forall integer n, integer ans;
      ans >= 0 && ans <= n ==> ans >= 0 && ans <= n;
*/

/*@
  requires n >= 1 && n <= 100000;
  requires k >= 1 && k <= 500;
  requires \valid(heights + (0 .. n-1));
  requires heights_in_range(heights, n);
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= (int)n;
*/
int func(size_t n, int k, int *heights) {
    int ans = 0;
    size_t index = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= index <= i;
        loop invariant ans >= 0;
        loop invariant ans == (int)(i - index);
        loop invariant heights_in_range(heights, n);
        loop assigns i, index, ans;
        loop variant n - i;
    */
    while (i < n) {
        int hi = heights[i];
        
        //@ assert 1 <= hi <= 500;
        
        if (hi >= k) {
            ans += 1;
        } else {
            index += 1;
        }
        
        i += 1;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= (int)n;
    return ans;
}
