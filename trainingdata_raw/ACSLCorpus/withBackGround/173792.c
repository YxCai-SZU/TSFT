#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(int *a, integer n) =
      n > 0 && n <= 100 &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
*/

/*@ predicate ans_bounds(integer ans, integer index) =
      ans >= 0 && ans <= index;
*/

/*@ lemma index_bounds: \forall integer n, integer index;
      0 <= index <= n && n > 0 ==> index >= 0;
*/

/*@
  requires n > 0 && n <= 100;
  requires \valid(a + (0 .. n-1));
  requires valid_array(a, n);
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= n;
*/
int func(int n, int *a) {
    int ans = 0;
    int index = 0;
    
    /*@
      loop invariant 0 <= index <= n;
      loop invariant ans_bounds(ans, index);
      loop invariant valid_array(a, n);
      loop assigns ans, index;
      loop variant n - index;
    */
    while (index < n) {
        int value = a[index];
        
        //@ assert value >= 1 && value <= 100;
        
        if (((index & 1) == 0) && ((value & 1) == 1)) {
            ans = ans + 1;
        }
        
        //@ assert ans_bounds(ans, index + 1);
        index += 1;
    }
    
    //@ assert ans_bounds(ans, n);
    return ans;
}
