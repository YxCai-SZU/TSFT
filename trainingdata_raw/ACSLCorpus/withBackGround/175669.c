#include <stdint.h>

/*@ predicate is_valid_params(integer n, integer k) =
     1 <= n <= 100 && 1 <= k <= 100;
*/

/*@ predicate remainder_invariant(integer r, integer n, integer k) =
     0 <= r <= n && k > 0;
*/

/*@ lemma remainder_decreases:
      \forall integer r, k; k > 0 && r >= k ==> r - k < r;
*/

/*@ requires is_valid_params(n, k);
    ensures \result >= 0 && \result <= 1;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t k) {
    int32_t result = 0;
    uint32_t remainder = n;
    
    /*@ loop invariant remainder_invariant(remainder, n, k);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= k) {
        //@ assert remainder >= k;
        remainder -= k;
    }
    
    if (remainder != 0) {
        result = 1;
    }
    
    return result;
}
