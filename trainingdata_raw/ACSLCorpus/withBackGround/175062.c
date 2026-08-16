#include <stdint.h>

/*@ predicate valid_params(integer n, integer a, integer b) =
     1 <= n && n <= 20 &&
     1 <= a && a <= 100 &&
     1 <= b && b <= 2000;
*/

/*@ logic integer max_product(integer n, integer a) = n * a; */

/*@ lemma product_bound: 
      \forall integer n, integer a, integer b;
        valid_params(n, a, b) ==> max_product(n, a) <= 2000;
*/

/*@
  requires valid_params(n, a, b);
  ensures \result == max_product(n, a) || \result == b;
  ensures \result <= b;
  assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t a, uint32_t b) {
    uint32_t result;
    
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 2000;
    //@ assert max_product(n, a) <= 2000;
    
    if (n * a < b) {
        result = n * a;
    } else {
        result = b;
    }
    
    return result;
}
