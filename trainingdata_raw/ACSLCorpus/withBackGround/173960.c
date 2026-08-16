#include <stdbool.h>

/*@ predicate is_valid_range(integer n, integer m) =
      1 <= n && n <= 100 &&
      1 <= m && m <= 100;
*/

/*@ predicate result_condition(integer n, integer m, bool result) =
      result == (m * 2 + 1 <= n);
*/

/*@
  requires is_valid_range(n, m);
  ensures result_condition(n, m, \result);
*/
bool func(int n, int m)
{
    bool result;
    //@ assert is_valid_range(n, m);
    
    if (m * 2 + 1 <= n) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result_condition(n, m, result);
    return result;
}
