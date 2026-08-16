#include <stdbool.h>

/*@ predicate is_valid_condition(integer a, integer b) =
      a == b || a - 1 == b || a - 2 == b;
*/

/*@
  requires 1 <= a <= 100;
  requires 0 <= b <= a;
  ensures \result == true <==> (a == b || a - 1 == b || a - 2 == b);
*/
bool func(int a, int b)
{
    bool is_valid = false;
    
    //@ assert is_valid == false;
    
    if (a == b || a - 1 == b || a - 2 == b)
    {
        is_valid = true;
    }
    
    //@ assert is_valid == true <==> (a == b || a - 1 == b || a - 2 == b);
    
    return is_valid;
}
