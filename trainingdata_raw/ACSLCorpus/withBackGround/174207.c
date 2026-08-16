#include <stddef.h>
#include <stdbool.h>

/*@ predicate valid_n(integer n) = 1 <= n && n <= 100; */
/*@ predicate valid_x(integer x) = 1 <= x && x <= 10000; */
/*@ predicate valid_array(integer n, int *l) = 
      \valid(l + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= l[i] && l[i] <= 100; */

/*@
  requires valid_n(n);
  requires valid_x(x);
  requires valid_array(n, l);
  ensures 1 <= \result;
  ensures \result <= n + 1;
  assigns \nothing;
*/
size_t func(size_t n, size_t x, int *l) {
    size_t d = 0;
    size_t ans = 1;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 1 <= ans <= i + 1;
      loop invariant d <= x;
      loop invariant \forall integer j; 0 <= j < i ==> 1 <= l[j] && l[j] <= 100;
      loop invariant \forall integer k; 0 <= k < n ==> 1 <= l[k] && l[k] <= 100;
      loop invariant valid_n(n);
      loop invariant valid_x(x);
      loop invariant d <= x + 100 * i;
      loop invariant 1 <= ans <= n + 1;
      loop assigns d, ans, i;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert d <= x + 100 * i;
        d += l[i];
        if (d > x) {
            break;
        }
        ans += 1;
        i += 1;
    }
    return ans;
}
