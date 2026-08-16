#include <stdbool.h>

/*@ predicate is_valid_params(integer k, integer x) =
      1 <= k && 1 <= x && k <= 100 && x <= 100000;
*/

/*@ predicate result_condition(integer k, integer x, bool result) =
      result == (k * 500 >= x);
*/

/*@
  requires is_valid_params(k, x);
  assigns \nothing;
  ensures result_condition(k, x, \result);
*/
bool func(int k, int x)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert k * 500 >= x ==> k * 500 >= x;
    
    result = (k * 500 >= x);
    return result;
}
