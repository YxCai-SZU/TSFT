#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_array(integer n, int *l) =
      n >= 1 && n <= 100 &&
      \valid(l + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> l[i] >= 1 && l[i] <= 100;
*/

/*@ predicate loop_invariant(integer n, int x, int *l, 
                             integer index, integer ans, integer d) =
      index >= 0 && index <= n &&
      ans >= 1 && ans <= index + 1 &&
      d >= 0 && d <= index * 100 &&
      \valid(l + (0 .. n-1)) &&
      \forall integer k; 0 <= k < n ==> l[k] >= 1 && l[k] <= 100;
*/

/*@ lemma ans_bounds: 
      \forall integer n, integer index, integer ans;
      (index >= 0 && index <= n && ans >= 1 && ans <= index + 1) ==> ans <= n + 1;
*/

/*@ requires n >= 1 && n <= 100;
    requires x >= 1 && x <= 10000;
    requires \valid(l + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> l[i] >= 1 && l[i] <= 100;
    assigns \nothing;
    ensures \result >= 1 && \result <= n + 1;
*/
int func(int n, int x, int *l) {
    int d = 0;
    int ans = 1;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant ans >= 1 && ans <= index + 1;
        loop invariant d >= 0 && d <= index * 100;
        loop invariant \forall integer k; 0 <= k < n ==> l[k] >= 1 && l[k] <= 100;
        loop assigns d, ans, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        //@ assert index < n;
        d += l[index];
        //@ assert d >= 0 && d <= (index + 1) * 100;
        
        if (d <= x) {
            ans += 1;
            //@ assert ans >= 2 && ans <= index + 2;
        } else {
            break;
        }
        index += 1;
        //@ assert ans <= index + 1;
    }
    
    //@ assert ans >= 1 && ans <= n + 1;
    return ans;
}
