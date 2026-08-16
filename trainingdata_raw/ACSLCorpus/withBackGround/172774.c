#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_array(integer n, uint32_t *a) =
      n >= 1 && n <= 100 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] <= 100;
*/

/*@ predicate even_count(integer n, uint32_t *a, integer res) =
      res >= 0 && res <= n &&
      \forall integer i; 0 <= i < n ==> (a[i] % 2 == 0 ==> res > 0);
*/

/*@ lemma array_properties_preserved:
      \forall integer n, uint32_t *a, integer i;
      valid_array(n, a) && 0 <= i <= n ==>
      \forall integer j; 0 <= j < n ==> 1 <= a[j] <= 100;
*/

/*@
  requires valid_array(n, a);
  ensures even_count(n, a, \result);
  assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t *a) {
    uint32_t res = 0;
    uint32_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant res >= 0;
      loop invariant res <= i;
      loop invariant \forall integer j; 0 <= j < i ==> (a[j] % 2 == 0 ==> res > 0);
      loop invariant valid_array(n, a);
      loop assigns i, res;
      loop variant n - i;
    */
    while (i < n) {
        //@ assert 0 <= i < n;
        if (a[i] % 2 == 0) {
            res += 1;
        }
        i += 1;
    }
    
    //@ assert even_count(n, a, res);
    return res;
}
