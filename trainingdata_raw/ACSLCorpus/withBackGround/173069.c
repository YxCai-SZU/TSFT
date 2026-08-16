#include <stdint.h>

/*@ predicate is_valid_params(integer n, integer k) =
      1 <= n && n <= 100 &&
      1 <= k && k <= 100;
*/

/*@ predicate result_meaning(integer n, integer k, integer result) =
      result == 0 || result == 1 &&
      (result == 0 ==> n % k == 0) &&
      (result == 1 ==> n % k != 0);
*/

/*@
  requires is_valid_params(n, k);
  assigns \nothing;
  ensures result_meaning(n, k, \result);
*/
int32_t func(uint32_t n, uint32_t k)
{
    int32_t result;
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= k && k <= 100;
    
    if (n % k == 0) {
        result = 0;
    } else {
        result = 1;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}

/*@
  requires is_valid_params(n, k);
  assigns \nothing;
  ensures result_meaning(n, k, \result);
*/
int32_t func_mod(uint32_t n, uint32_t k)
{
    int32_t result;
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= k && k <= 100;
    
    //@ assert n % k == n % k;
    
    if (n % k == 0) {
        result = 0;
    } else {
        result = 1;
    }
    
    //@ assert result == 0 || result == 1;
    return result;
}
