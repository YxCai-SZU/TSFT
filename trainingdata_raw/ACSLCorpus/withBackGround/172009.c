#include <stddef.h>
#include <stdbool.h>

/*@ predicate heights_in_range(int *heights, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= heights[i] <= 500;
*/

/*@ predicate ans_correct(int *heights, integer n, integer k, integer ans, integer idx) =
      \forall integer j; 0 <= j < idx ==> (heights[j] >= k ==> ans >= 1);
*/

/*@ lemma bounds_lemma:
      \forall integer n, integer k;
      1 <= n <= 100000 && 1 <= k <= 500 ==> n >= 1 && k >= 1;
*/

/*@
  requires 1 <= n <= 100000;
  requires 1 <= k <= 500;
  requires \valid(heights + (0 .. n-1));
  requires heights_in_range(heights, n);
  assigns \nothing;
  ensures 0 <= \result <= n;
  ensures \forall integer i; 0 <= i < n ==> (heights[i] >= k ==> \result >= 1);
*/
int func(int n, int k, int *heights) {
    int ans = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= ans <= index;
      loop invariant heights_in_range(heights, n);
      loop invariant ans_correct(heights, n, k, ans, index);
      loop assigns ans, index;
      loop variant n - index;
    */
    while (index < n) {
        int h = heights[index];
        if (h >= k) {
            ans += 1;
        }
        index += 1;
    }
    return ans;
}
