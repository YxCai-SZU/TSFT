#include <stdbool.h>
#include <stdint.h>

/*@ predicate is_valid_range(int i, integer n) = 0 <= i < n; */
/*@ predicate is_valid_height(integer h) = 1 <= h && h <= 500; */
/*@ predicate count_condition(integer h, integer k, integer num) = h >= k ==> num > 0; */

/*@
  lemma height_bounds:
    \forall integer i, integer n, uint32_t *h;
    (0 <= i < n && \forall integer j; 0 <= j < n ==> 1 <= h[j] && h[j] <= 500) ==>
    1 <= h[i] && h[i] <= 500;
*/

/*@
  requires n > 0;
  requires k > 0;
  requires \forall integer i; 0 <= i < n ==> is_valid_height(h[i]);
  ensures \result <= n;
  ensures \forall integer i; 0 <= i < n ==> (h[i] >= k ==> \result > 0);
  assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t k, uint32_t *h) {
    uint32_t num = 0;
    uint32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant num <= i;
      loop invariant \forall integer j; 0 <= j < i ==> (h[j] >= k ==> num > 0);
      loop assigns i, num;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert is_valid_height(h[i]);
        if (h[i] >= k) {
            num = num + 1;
        }
        i = i + 1;
    }
    return num;
}
