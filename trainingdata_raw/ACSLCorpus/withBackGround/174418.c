#include <stddef.h>

/*@ predicate valid_params(integer n, integer k) =
      n >= 1 && n <= 100000 &&
      k >= 1 && k <= 500;
*/

/*@ predicate valid_array(int *h, integer n) =
      \forall integer i; 0 <= i < n ==> h[i] >= 1 && h[i] <= 500;
*/

/*@ predicate count_property(integer count, integer n, int *h, integer k) =
      count >= 0 && count <= n &&
      \forall integer i; 0 <= i < n ==> (h[i] >= k ==> count > 0);
*/

/*@ lemma loop_invariant_maintained:
      \forall integer i, integer count, integer n, int *h, integer k;
      valid_params(n, k) && valid_array(h, n) &&
      0 <= i <= n && 0 <= count <= i &&
      (\forall integer j; 0 <= j < i ==> (h[j] >= k ==> count > 0)) ==>
      (i < n ==> (h[i] >= k ==> count + 1 > 0));
*/

/*@
  requires valid_params(n, k);
  requires \valid(h + (0 .. n-1));
  requires valid_array(h, n);
  assigns \nothing;
  ensures count_property(\result, n, h, k);
*/
size_t func(size_t n, size_t k, int *h) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= i;
      loop invariant valid_array(h, n);
      loop invariant \forall integer j; 0 <= j < i ==> (h[j] >= k ==> count > 0);
      loop invariant valid_params(n, k);
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (h[i] >= k) {
            //@ assert h[i] >= k ==> count + 1 > 0;
            count++;
        }
        i++;
    }
    return count;
}
