#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(integer n) = 3 <= n <= 200000; */

/*@ predicate valid_array(int *ps, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= ps[i] <= n; */

/*@ predicate distinct_array(int *ps, integer n) =
      \forall integer i, j; 0 <= i < j < n ==> ps[i] != ps[j]; */

/*@ predicate ans_bounds(integer ans, integer n) =
      ans >= 0 && ans <= n - 2; */

/*@ lemma ans_upper_bound:
      \forall integer i, n; 1 <= i <= n-1 ==> i-1 <= n-2; */

/*@
  requires valid_range(n);
  requires \valid(ps + (0 .. n-1));
  requires valid_array(ps, n);
  requires distinct_array(ps, n);
  assigns \nothing;
  ensures ans_bounds(\result, n);
*/
int func(size_t n, int *ps) {
    int ans = 0;
    size_t i = 1;
    
    /*@
      loop invariant 1 <= i <= n-1;
      loop invariant ans >= 0;
      loop invariant ans <= i-1;
      loop invariant valid_array(ps, n);
      loop invariant distinct_array(ps, n);
      loop invariant valid_range(n);
      loop assigns ans, i;
      loop variant n-i;
    */
    while (i < n - 1) {
        int p = ps[i];
        int p_before = ps[i - 1];
        int p_after = ps[i + 1];
        
        //@ assert p_before != p && p != p_after;
        
        if ((p_before < p && p < p_after) || (p_before > p && p > p_after)) {
            ans += 1;
        }
        
        //@ assert ans <= i;
        i += 1;
    }
    
    //@ assert ans_bounds(ans, n);
    return ans;
}
