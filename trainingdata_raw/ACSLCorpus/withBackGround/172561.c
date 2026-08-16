#include <stdint.h>

/*@ predicate bounds(integer n, integer k) =
      1 <= n <= 100 &&
      1 <= k <= n;
*/

/*@ logic integer result_value(integer n, integer k) =
      n - k + 1;
*/

/*@ lemma result_bounds: \forall integer n, integer k;
      bounds(n, k) ==> 0 <= result_value(n, k) <= n;
*/

/*@ lemma result_type_bounds: \forall integer n, integer k;
      bounds(n, k) ==> 0 <= (int64_t)result_value(n, k) <= n;
*/

/*@
  requires 1 <= n <= 100 && 1 <= k <= n;
  ensures \result >= 0 && \result <= n && \result == (int64_t)(n - k + 1);
*/
int64_t func(uint32_t n, uint32_t k)
{
    // Variable declarations at top of scope
    int64_t result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= k <= n;
    //@ assert n - k + 1 >= 0;
    //@ assert n - k + 1 <= 100;
    //@ assert (int64_t)(n - k + 1) >= 0;
    //@ assert (int64_t)(n - k + 1) <= 100;
    //@ assert n - k + 1 <= n;
    
    result = (int64_t)(n - k + 1);
    return result;
}
