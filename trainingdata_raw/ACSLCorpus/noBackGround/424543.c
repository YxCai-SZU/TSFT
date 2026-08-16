#include <stdbool.h>

/*@
  requires n == len;
  requires 1 <= n && n <= 100000;
  requires 1 <= k && k <= 500;
  requires \valid(heights + (0 .. n-1));
  requires (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(int n, int k, int *heights, int len) {
    int ans = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant 0 <= ans <= index;
      loop invariant n == len;
      loop invariant 1 <= k && k <= 500;
      loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
      loop invariant (\forall integer i; 0 <= i < (index) ==> ((heights)[i] >= (k) ==> (ans) > 0));
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
