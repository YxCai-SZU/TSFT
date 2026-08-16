#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(int *a, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
*/

/*@ predicate loop_invariant(int *a, integer n, integer index, integer x_remaining, integer x, integer ans) =
      0 <= index <= n &&
      0 <= x_remaining <= x &&
      0 <= ans <= index &&
      (index > 0 ==> \forall integer i; 0 <= i < index ==> 1 <= a[i] <= 100) &&
      1 <= n <= 100 &&
      1 <= x <= 100;
*/

/*@ lemma loop_decreases: \forall integer n, integer index; 0 <= index <= n ==> n - index >= 0; */

/*@
  requires 1 <= n <= 100;
  requires 1 <= x <= 100;
  requires \valid(a + (0 .. n-1));
  requires is_valid_array(a, n);
  assigns \nothing;
  ensures 0 <= \result <= n;
*/
int func(int n, int x, int *a) {
    int ans = 0;
    int x_remaining = x;
    int index = 0;
    
    /*@
      loop invariant loop_invariant(a, n, index, x_remaining, x, ans);
      loop assigns ans, x_remaining, index;
      loop variant n - index;
    */
    while (index < n && x_remaining >= a[index]) {
        //@ assert index >= 0 && index < n;
        x_remaining -= a[index];
        ans += 1;
        index += 1;
    }
    
    //@ assert 0 <= ans <= n;
    return ans;
}
