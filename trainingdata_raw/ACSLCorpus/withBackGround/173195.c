#include <stdbool.h>

/*@ predicate is_possible(integer a, integer b, integer x) =
      x >= 0 && x <= a + b && a <= x;
*/

/*@
    requires 0 <= a <= 50;
    requires 0 <= b <= 50;
    requires 0 <= x <= 50;
    requires a + b + x <= 50;
    ensures \result == (x >= 0 && x <= a + b && a <= x);
*/
bool is_possible_to_have_x_cats(int a, int b, int x)
{
    //@ assert a + b + x <= 50;
    
    if (x < 0 || a + b < x || a > x)
    {
        //@ assert !(x >= 0 && x <= a + b && a <= x);
        return false;
    }
    
    //@ assert x >= 0 && x <= a + b && a <= x;
    return true;
}
