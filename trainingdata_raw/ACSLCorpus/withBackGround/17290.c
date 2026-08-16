#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_range(int *h, integer n) =
      \forall integer i; 0 <= i < n ==> 1 <= h[i] <= 100;
*/

/*@ predicate ans_bounds(integer ans, integer i, integer n) =
      ans >= 0 && ans <= i - 1 && i < n;
*/

/*@
  requires 3 <= n <= 200000;
  requires \valid(h+(0..n-1));
  requires valid_range(h, n);
  assigns \nothing;
  ensures \result >= 0;
  ensures \result <= n - 2;
*/
int func(int n, int *h) {
    int ans = 0;
    int i = 1;
    bool cur = h[0] <= h[1];
    
    /*@
      loop invariant 1 <= i < n;
      loop invariant valid_range(h, n);
      loop invariant ans_bounds(ans, i, n);
      loop invariant 3 <= n <= 200000;
      loop assigns ans, i, cur;
      loop variant n - i;
    */
    while (i < n - 1) {
        bool next = h[i] <= h[i + 1];
        
        //@ assert cur ^ next ==> (cur && !next) || (!cur && next);
        if (cur ^ next) {
            ans += 1;
        }
        cur = next;
        i += 1;
    }
    return ans;
}
