#include <limits.h>

/*@ predicate is_valid_array(integer n, int *a) =
      n >= 1 && n <= 100 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> a[i] >= 1 && a[i] <= 100;
*/

/*@ logic integer min_value(integer x, integer y) =
      x < y ? x : y;
*/

/*@ lemma ans_non_negative:
      \forall integer ans; ans >= 0 ==> min_value(0, ans) >= 0;
*/

/*@ requires is_valid_array(n, a);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int n, int *a) {
    int ans = INT_MAX;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant ans >= 0;
        loop assigns i, ans;
        loop variant n - i;
    */
    while (i < n) {
        int a_iter = a[i];
        int is_even = (a_iter & 1) == 0;
        int x = is_even ? 0 : 1;
        
        //@ assert x == 0 || x == 1;
        
        ans = x < ans ? x : ans;
        
        //@ assert ans >= 0;
        
        i = i + 1;
    }
    
    return ans;
}
