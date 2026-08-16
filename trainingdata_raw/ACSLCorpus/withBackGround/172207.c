#include <stdbool.h>
#include <stdint.h>

/*@ predicate valid_params(integer n, integer k) =
      1 <= n && n <= 100 &&
      1 <= k && k <= 100;
*/

/*@ predicate loop_inv(integer n, integer k, integer i, integer a, integer result) =
      1 <= n && n <= 100 &&
      1 <= k && k <= 100 &&
      1 <= i && i <= n &&
      0 <= a && a < k &&
      0 <= result && result <= 1;
*/

/*@ lemma loop_decreases: \forall integer n, i; i < n ==> n - i > 0; */

/*@
  requires valid_params(n, k);
  ensures 0 <= \result && \result <= 1;
*/
int32_t func(uint32_t n, uint32_t k) {
    int32_t result = 0;
    uint32_t a = 7 % k;
    uint32_t i = 1;
    
    //@ assert loop_inv(n, k, i, a, result);
    
    /*@
      loop invariant loop_inv(n, k, i, a, result);
      loop assigns i, a, result;
      loop variant n - i;
    */
    while (i < n) {
        if (a == 0) {
            result = 1;
            break;
        }
        a = (a * 10 + 7) % k;
        i = i + 1;
        
        //@ assert loop_inv(n, k, i, a, result);
    }
    
    if (a == 0) {
        result = 1;
    }
    
    //@ assert 0 <= result && result <= 1;
    return result;
}
