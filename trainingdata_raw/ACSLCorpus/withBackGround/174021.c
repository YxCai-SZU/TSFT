#include <limits.h>
#include <stdbool.h>

/*@ predicate valid_array(integer n, int *a) =
      n >= 2 && n <= 200000 &&
      \forall integer j; 0 <= j < n ==> 1 <= a[j] <= 1000000000;
*/

/*@ lemma result_bounds:
      \forall integer n, int *a, int result;
      valid_array(n, a) && result >= 0 ==> result >= 0;
*/

/*@
    requires 2 <= n <= 200000;
    requires \valid(a + (0 .. n-1));
    requires valid_array(n, a);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int *a) {
    int result = INT_MAX;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= n;
        loop invariant result >= 0;
        loop invariant result <= INT_MAX;
        loop invariant valid_array(n, a);
        loop assigns i, result;
        loop variant n - i;
    */
    while (i < n) {
        int diff = a[i] - a[i - 1];
        int abs_diff = diff < 0 ? -diff : diff;
        
        //@ assert abs_diff >= 0;
        
        if (result > abs_diff) {
            result = abs_diff;
        }
        
        i++;
    }
    
    return result;
}
