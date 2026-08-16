#include <stddef.h>

/*@ predicate valid_params(integer n, int *h) =
     1 <= n && n <= 20 &&
     \valid(h+(0..n-1)) &&
     \forall integer j; 0 <= j < n ==> 1 <= h[j] && h[j] <= 100;
*/

/*@ predicate loop_invariant(integer n, int *h, integer i, integer count) =
     0 <= i <= n-1 &&
     0 <= count <= i &&
     valid_params(n, h);
*/

/*@ lemma result_bounds:
     \forall integer n, integer count;
     loop_invariant(n, \null, n-1, count) ==> 0 <= count <= n-1;
*/

/*@
  requires valid_params(n, h);
  ensures 0 <= \result <= n-1;
  assigns \nothing;
*/
int func(size_t n, int *h) {
    int count = 0;
    size_t i = 0;
    
    /*@
      loop invariant loop_invariant(n, h, i, count);
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i < n-1;
        
        if (h[i] >= h[i + 1]) {
            count += 1;
        } else {
            count = 0;
        }
        i += 1;
    }
    
    //@ assert 0 <= count <= n-1;
    return count;
}
