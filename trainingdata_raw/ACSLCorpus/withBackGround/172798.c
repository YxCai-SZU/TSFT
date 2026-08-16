#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *a, integer n) =
      n >= 2 && n <= 100000 &&
      \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 1000000000;
*/

/*@ predicate ans_in_range(integer ans) =
      ans >= 1 && ans <= 1000000000;
*/

/*@ lemma n_bounds: \forall integer n; 2 <= n <= 100000 ==> n >= 2 && n <= 100000; */

/*@
  requires \valid(a + (0 .. n-1));
  requires valid_array(a, n);
  ensures \result >= 0 || \result == -1;
  ensures \result >= 0 ==> ans_in_range(\result);
  ensures \result == -1 ==> 2 <= n <= 100000;
*/
int func(int n, int *a) {
    int ans = -1;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant ans == -1 || ans_in_range(ans);
      loop invariant \forall integer j; 0 <= j < i ==> a[j] >= 1 && a[j] <= 1000000000;
      loop invariant 2 <= n <= 100000;
      loop invariant valid_array(a, n);
      loop assigns i, ans;
      loop variant n - i;
    */
    while (i < n) {
        int a_i = a[i];
        
        if (ans == -1) {
            //@ assert a_i >= 1 && a_i <= 1000000000;
            ans = a_i;
        } else {
            if (a_i != ans) {
                ans = -1;
            }
        }
        i++;
    }
    
    return ans;
}
